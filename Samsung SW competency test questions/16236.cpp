#include <iostream>
#include <queue>

using namespace std;

int N, Answer;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Map[21][21];

pair<int, int> FindFish(bool &bCanEat, int Row, int Col, int Size)
{
    queue<pair<pair<int, int>, int>> Queue;
    vector<pair<pair<int, int>, int>> FoundFish;
    vector<vector<bool>> IsVisited(N, vector<bool>(N, false));

    Queue.emplace(make_pair(make_pair(Row, Col), 0));
    IsVisited[Row][Col] = true;

    while (!Queue.empty())
    {
        int CurrentRow = Queue.front().first.first;
        int CurrentCol = Queue.front().first.second;
        int Distance = Queue.front().second;
        Queue.pop();

        if (Map[CurrentRow][CurrentCol] != 0 && Map[CurrentRow][CurrentCol] != 9 && Map[CurrentRow][CurrentCol] != Size)
        {
            FoundFish.emplace_back(make_pair(make_pair(CurrentRow, CurrentCol), Distance));
        }

        for (int k = 0; k < 4; ++k)
        {
            int NextRow = CurrentRow + drow[k];
            int NextCol = CurrentCol + dcol[k];

            if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= N)
                continue;

            if (IsVisited[NextRow][NextCol])
                continue;

            // 자신보다 큰 물고기는 못 지나감
            if (Map[NextRow][NextCol] > Size)
                continue;

            Queue.emplace(make_pair(make_pair(NextRow, NextCol), Distance + 1));
            IsVisited[NextRow][NextCol] = true;
        }
    }

    if (FoundFish.size() == 0)
    {
        return {-1, -1};
    }
    else if (FoundFish.size() == 1)
    {
        bCanEat = true;
        Answer += FoundFish[0].second;
        return FoundFish[0].first;
    }
    else
    {
        bCanEat = true;
        // 거리가 가장 가까운 물고기를 먹으러 간다
        int MinDistance = 1e9;
        pair<pair<int, int>, int> TargetFish;
        for (int i = 0; i < FoundFish.size(); ++i)
        {
            int Distance = FoundFish[i].second;
            if (Distance < MinDistance)
            {
                MinDistance = Distance;
                TargetFish = FoundFish[i];
            }
            else if (Distance == MinDistance)
            {
                // row 가장 작은것
                if (FoundFish[i].first.first < TargetFish.first.first)
                {
                    TargetFish = FoundFish[i];
                }
                else if (FoundFish[i].first.first == TargetFish.first.first)
                {
                    // col 가장 작은 것
                    if (FoundFish[i].first.second < TargetFish.first.second)
                    {
                        TargetFish = FoundFish[i];
                    }
                }
            }
        }
        Answer += MinDistance;
        return TargetFish.first;
    }
}

void Solve(int Row, int Col, int NumOfAte, int Size)
{
    bool bCanEat = false;
    pair<int, int> Point = FindFish(bCanEat, Row, Col, Size);

    if (bCanEat)
    {
        Map[Row][Col] = 0;
        Map[Point.first][Point.second] = 9;
        if (++NumOfAte == Size)
        {
            NumOfAte = 0;
            ++Size;
        }
        Solve(Point.first, Point.second, NumOfAte, Size);
    }
    else
    {
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int StartRow, StartCol;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            cin >> Map[row][col];
            if (Map[row][col] == 9)
            {
                StartRow = row;
                StartCol = col;
            }
        }
    }

    Solve(StartRow, StartCol, 0, 2);
    cout << Answer << endl;
}