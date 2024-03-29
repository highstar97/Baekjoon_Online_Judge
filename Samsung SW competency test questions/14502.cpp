#include <iostream>
#include <queue>
#include <vector>

#define MAX 8
using namespace std;

int N, M, NumOfWall, Answer = 0;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Map[MAX][MAX];
int BFSMap[MAX][MAX];

void BFS()
{
    vector<vector<bool>> IsVisited(N, vector<bool>(M, false));
    queue<pair<int, int>> Queue;
    // BFS용 Map 복사
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            BFSMap[row][col] = Map[row][col];
            // 바이러스 발견시 Queue에 추가
            if (BFSMap[row][col] == 2)
            {
                Queue.emplace(make_pair(row, col));
                IsVisited[row][col] = true;
            }
        }
    }

    // BFS 계산
    while (!Queue.empty())
    {
        int CurrentRow = Queue.front().first;
        int CurrentCol = Queue.front().second;
        Queue.pop();

        for (int k = 0; k < 4; ++k)
        {
            int NextRow = CurrentRow + drow[k];
            int NextCol = CurrentCol + dcol[k];

            if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= M)
                continue;

            if (IsVisited[NextRow][NextCol])
                continue;

            if (BFSMap[NextRow][NextCol] == 0)
            {
                Queue.emplace(make_pair(NextRow, NextCol));
                IsVisited[NextRow][NextCol] = true;
                BFSMap[NextRow][NextCol] = 2;
            }
        }
    }

    int NumOfSafe = 0;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            if (BFSMap[row][col] == 0)
            {
                ++NumOfSafe;
            }
        }
    }
    Answer = max(Answer, NumOfSafe);
}

void MakeWall()
{
    if (NumOfWall == 3)
    {
        return BFS();
    }

    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            if (Map[row][col] == 0)
            {
                ++NumOfWall;
                Map[row][col] = 1;
                MakeWall();
                --NumOfWall;
                Map[row][col] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> Map[row][col];
        }
    }

    MakeWall();

    cout << Answer;
}