/*
    벽 부수고 이동하기
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, Answer;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Map[1000][1000];
bool IsVisited[1000][1000][2];

struct Point
{
    int row;
    int col;

    Point() : row(0), col(0) {};
    Point(int row, int col) : row(row), col(col) {};
};

struct Data
{
    int Distance;
    int NumOfBreak;

    Data() : Distance(0), NumOfBreak(0) {};
    Data(int Distance, int NumOfBreak) : Distance(Distance), NumOfBreak(NumOfBreak) {};
};

void BFS(Point Start, Data StartData)
{
    queue<pair<Point, Data>> Queue;
    Queue.emplace(make_pair(Start, StartData));
    IsVisited[Start.row][Start.col][0] = true;

    while (!Queue.empty())
    {
        Point CurrentPoint = Queue.front().first;
        Data CurrentData = Queue.front().second;
        Queue.pop();

        if (CurrentPoint.row == N - 1 && CurrentPoint.col == M - 1)
            Answer = Answer == 0 ? Answer = CurrentData.Distance : min(Answer, CurrentData.Distance);

        Point NextPoint;
        Data NextData;
        for (int k = 0; k < 4; ++k)
        {
            NextPoint.row = CurrentPoint.row + drow[k];
            NextPoint.col = CurrentPoint.col + dcol[k];

            if (NextPoint.row < 0 || NextPoint.row >= N || NextPoint.col < 0 || NextPoint.col >= M)
                continue;

            if (Map[NextPoint.row][NextPoint.col] == 0)
            {
                if (IsVisited[NextPoint.row][NextPoint.col][CurrentData.NumOfBreak])
                    continue;

                NextData.Distance = CurrentData.Distance + 1;
                NextData.NumOfBreak = CurrentData.NumOfBreak;
            }
            else
            {
                if (CurrentData.NumOfBreak == 1 || IsVisited[NextPoint.row][NextPoint.col][CurrentData.NumOfBreak])
                    continue;

                NextData.Distance = CurrentData.Distance + 1;
                NextData.NumOfBreak = CurrentData.NumOfBreak + 1;
            }
            Queue.emplace(make_pair(NextPoint, NextData));
            IsVisited[NextPoint.row][NextPoint.col][NextData.NumOfBreak] = true;
        }
    }
    Answer == 0 ? Answer = -1 : Answer = Answer;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; ++j)
        {
            char input_char = input[j] - '0';
            Map[i][j] = input_char;
        }
    }

    Point Start(0, 0);
    Data StartData(1, 0);
    BFS(Start, StartData);
    cout << Answer;
}