#include <iostream>
#include <queue>

using namespace std;

int N, K, L, Time;
int drow[4] = {-1, 0, 1, 0}; // 위 오른 아래 왼
int dcol[4] = {0, 1, 0, -1};
int Board[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> Snake;
    queue<pair<int, char>> qDir;

    cin >> N;

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int row, col;
        cin >> row >> col;
        Board[row][col] = 1; // 사과 : 1
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int time;
        char dir;

        cin >> time >> dir;

        qDir.push(make_pair(time, dir));
    }

    int NextHeadRow = 1;
    int NextHeadCol = 2;
    int Dir = 1; // 0 : 위 1 : 오른 2 : 아래 3 : 왼
    int Time = 1;

    Snake.push(make_pair(1, 1)); // 초기 뱀 모양
    Board[1][1] = 2;              // 뱀 : 2

    while (1)
    {
        if (NextHeadRow > N || NextHeadCol > N || NextHeadRow < 1 || NextHeadCol < 1)
            break;

        if (Board[NextHeadRow][NextHeadCol] == 2)
            break;

        if (!qDir.empty())
        {
            if (Time == qDir.front().first)
            {
                if (qDir.front().second == 'L') // 왼쪽으로 회전
                    Dir = (Dir + 3) % 4;
                else if (qDir.front().second == 'D') // 오른쪽으로 회전
                    Dir = (Dir + 1) % 4;

                qDir.pop();
            }
        }

        if (Board[NextHeadRow][NextHeadCol] == 0)
        {
            Snake.push(make_pair(NextHeadRow, NextHeadCol));
            Board[Snake.front().first][Snake.front().second] = 0;
            Snake.pop();
        }

        else if (Board[NextHeadRow][NextHeadCol] == 1)
        {
            Snake.push(make_pair(NextHeadRow, NextHeadCol));
        }

        Board[NextHeadRow][NextHeadCol] = 2;

        NextHeadRow = NextHeadRow + drow[Dir];
        NextHeadCol = NextHeadCol + dcol[Dir];

        Time++;
    }

    cout << Time;

    return 0;
}