#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

int N, M, K, Answer;
int Parent[MAX];

int Find(int a)
{
    if (Parent[a] == a)
    {
        return a;
    }
    return Parent[a] = Find(Parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    a > b ? Parent[a] = b : Parent[b] = a;
}

int main()
{
    cin >> N >> M;
    // Init Parent
    for (int i = 1; i <= N; ++i)
    {
        Parent[i] = i;
    }
    vector<vector<int>> Participants(M, vector<int>());

    /*
        ex) N is 10 And 1, 2, 3, 4 know truth
        Parent = {0,0,0,0,5,6,7,8,9,10}
    */
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int input;
        cin >> input;
        Parent[input] = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int NumOfParticipant;
        cin >> NumOfParticipant;
        for (int j = 0; j < NumOfParticipant; ++j)
        {
            int Participant;
            cin >> Participant;
            Participants[i].emplace_back(Participant);
        }

        if (NumOfParticipant == 1)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < NumOfParticipant - 1; ++j)
            {
                Union(Participants[i][j], Participants[i][j + 1]);
            }
        }
    }

    // Important!
    for (int i = 1; i <= N; ++i)
    {
        Find(i);
    }

    // After Union, Find Answer
    for (int i = 0; i < M; ++i)
    {
        bool bCanLie = true;
        for (int j = 0; j < Participants[i].size(); ++j)
        {
            // Somebody know Truth, CanLie set false.
            if (Parent[Participants[i][j]] == 0)
            {
                bCanLie = false;
                break;
            }
        }

        if (bCanLie)
        {
            ++Answer;
        }
    }

    cout << Answer;
}