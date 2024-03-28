#include <iostream>
#define MAX 1001
using namespace std;

int N, M, Answer;
int Arr[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; ++j)
        {
            Arr[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            Arr[i][j] = min(Arr[i][j + 1], min(Arr[i + 1][j + 1], Arr[i + 1][j])) + 1;
            if (Answer < Arr[i][j])
            {
                Answer = Arr[i][j];
            }
        }
    }

    cout << Answer * Answer;
}