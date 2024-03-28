#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1e9
using namespace std;

int N, M;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
bool IsVisited[11][11][11][11];

struct Point
{
    int row;
    int col;
};

void BFS(Point Red, Point Blue, vector<vector<char>> &Board)
{
    queue<pair<pair<Point, Point>, int>> Queue;
    Queue.emplace(make_pair(make_pair(Red, Blue), 0));
    IsVisited[Red.row][Red.col][Blue.row][Blue.col] = true;

    while (!Queue.empty())
    {
        Point CurrentRed, CurrentBlue;
        CurrentRed.row = Queue.front().first.first.row;
        CurrentRed.col = Queue.front().first.first.col;
        CurrentBlue.row = Queue.front().first.second.row;
        CurrentBlue.col = Queue.front().first.second.col;
        int Count = Queue.front().second;
        Queue.pop();

        if (Count >= 10)
            break;

        for (int k = 0; k < 4; ++k)
        {
            Point NextRed, NextBlue;
            NextRed = CurrentRed;
            NextBlue = CurrentBlue;
            int RedCount = Count;
            int BlueCount = Count;

            // Move Red, Until blocked by Wall or Hole
            while (Board[NextRed.row + drow[k]][NextRed.col + dcol[k]] != '#' && Board[NextRed.row][NextRed.col] != 'O')
            {
                NextRed.row += drow[k];
                NextRed.col += dcol[k];
                ++RedCount;
            }
            // Move Blue, Until blocked by Wall or Hole
            while (Board[NextBlue.row + drow[k]][NextBlue.col + dcol[k]] != '#' && Board[NextBlue.row][NextBlue.col] != 'O')
            {
                NextBlue.row += drow[k];
                NextBlue.col += dcol[k];
                ++BlueCount;
            }

            // Blue가 홀에 들어간 경우 최대한 피하기 -> continue
            if (Board[NextBlue.row][NextBlue.col] == 'O')
                continue;

            if (Board[NextRed.row][NextRed.col] == 'O')
            {
                cout << Count + 1;
                return;
            }

            // Red와 Blue가 같은 위치라면 더 많이 움직인 공을 한 칸 뒤로
            if (NextRed.row == NextBlue.row && NextRed.col == NextBlue.col)
            {
                if (RedCount > BlueCount)
                {
                    NextRed.row -= drow[k];
                    NextRed.col -= dcol[k];
                }
                else
                {
                    NextBlue.row -= drow[k];
                    NextBlue.col -= dcol[k];
                }
            }

            if (IsVisited[NextRed.row][NextRed.col][NextBlue.row][NextBlue.col] == true)
                continue;
            IsVisited[NextRed.row][NextRed.col][NextBlue.row][NextBlue.col] = true;
            Queue.emplace(make_pair(make_pair(NextRed, NextBlue), Count + 1));
        }
    }
    cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    Point Red, Blue;
    cin >> N >> M;

    vector<vector<char>> Board(N, vector<char>(M));

    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> Board[row][col];
            if (Board[row][col] == 'R')
            {
                Red.row = row;
                Red.col = col;
            }
            if (Board[row][col] == 'B')
            {
                Blue.row = row;
                Blue.col = col;
            }
        }
    }

    // Solution
    BFS(Red, Blue, Board);
}