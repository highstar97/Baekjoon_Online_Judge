#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 50
#define min(a, b) a < b ? a : b

using namespace std;

int N, M, NumOfEmpty, Answer = 1e9;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
bool IsSelected[10];
int Map[MAX][MAX];
int Time[MAX][MAX];
vector<pair<int, int>> Virus;

void Imfect(queue<pair<int, int>> Queue)
{
    int NumOfImfected = 0;
    int MaxTime = 0;
    while (!Queue.empty())
    {
        int CurrentRow = Queue.front().first;
        int CurrentCol = Queue.front().second;
        Queue.pop();

        for (int k = 0; k < 4; ++k)
        {
            int NextRow = CurrentRow + drow[k];
            int NextCol = CurrentCol + dcol[k];

            if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= N)
                continue;

            if (Map[NextRow][NextCol] == 1)
                continue;

            if (Time[NextRow][NextCol] != -1)
                continue;

            // 비활성 바이러스, 빈칸에 대해서
            Time[NextRow][NextCol] = Time[CurrentRow][CurrentCol] + 1;
            Queue.emplace(make_pair(NextRow, NextCol));
            // 빈칸에 대해서는 특별히
            if (Map[NextRow][NextCol] == 0)
            {
                ++NumOfImfected;
                MaxTime = Time[NextRow][NextCol]; // 비활성 바이러스는 최종 시간에 영향을 미치지 않음
            }
        }
    }

    if (NumOfEmpty == NumOfImfected) // 모두 퍼트렸을때만 업데이트
    {
        Answer = min(Answer, MaxTime);
    }
}

void Select(int Index, int Depth)
{
    if (Depth == M)
    {
        queue<pair<int, int>> Queue;

        memset(Time, -1, sizeof(Time));

        for (int i = 0; i < Virus.size(); ++i)
        {
            if (IsSelected[i])
            {
                Queue.emplace(make_pair(Virus[i].first, Virus[i].second));
                Time[Virus[i].first][Virus[i].second] = 0;
            }
        }
        Imfect(Queue);
        return;
    }

    for (int i = Index; i < Virus.size(); ++i)
    {
        if (IsSelected[i])
            continue;

        IsSelected[i] = true;
        Select(Index + 1, Depth + 1);
        IsSelected[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            cin >> Map[row][col];
            if (Map[row][col] == 0)
            {
                ++NumOfEmpty;
            }
            else if (Map[row][col] == 2)
            {
                Virus.emplace_back(make_pair(row, col));
            }
        }
    }

    Select(0, 0);

    if (Answer == 1e9)
        cout << -1 << '\n';
    else
        cout << Answer << '\n';
}