#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Answer = 1e9;
int Power[20][20];

void BT(int Index, vector<int> TeamStart)
{
    if (Index == N / 2)
    {
        int SumOfTeamStart = 0;
        int SumOfTeamLink = 0;
        vector<int> TeamLink;

        for (int i = 0; i < N; ++i)
        {
            // i : TeamLink Player
            if (find(TeamStart.begin(), TeamStart.end(), i) == TeamStart.end())
            {
                TeamLink.emplace_back(i);
            }
        }

        for (int i = 0; i < N / 2; ++i)
        {
            for (int j = 0; j < N / 2; ++j)
            {
                SumOfTeamStart += Power[TeamStart[i]][TeamStart[j]];
                SumOfTeamLink += Power[TeamLink[i]][TeamLink[j]];
            }
        }

        Answer = min(Answer, abs(SumOfTeamLink - SumOfTeamStart));

        return;
    }

    for (int i = 0; i < N; ++i)
    {
        // i가 Team Start에 존재하면
        if (TeamStart.size() > 0 && *TeamStart.rbegin() >= i)
        {
            continue;
        }

        TeamStart.emplace_back(i);
        BT(Index + 1, TeamStart);
        TeamStart.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> TeamStart;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Power[i][j];
        }
    }

    BT(0, TeamStart);
    cout << Answer << endl;
}