#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R, Answer;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Map[51][51];

void Solve()
{
    bool bIsOpen = false; // 한번이라도 국경이 열리면 true;
    vector<vector<bool>> IsVisited(N, vector<bool>(N, false));

    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            // 이미 방문한 국가면 패싱
            if (IsVisited[row][col])
                continue;

            int Sum = 0;
            queue<pair<int, int>> Queue;  // BFS용
            queue<pair<int, int>> Queue2; // 합쳐진 국가 저장용
            Queue.emplace(make_pair(row, col));
            Queue2.emplace(make_pair(row, col));
            IsVisited[row][col] = true;
            Sum += Map[row][col];

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

                    if (IsVisited[NextRow][NextCol])
                        continue;

                    int Diff = abs(Map[CurrentRow][CurrentCol] - Map[NextRow][NextCol]);
                    // 국경이 열릴 조건이면 Queue에 추가
                    if (L <= Diff && Diff <= R)
                    {
                        Queue.emplace(make_pair(NextRow, NextCol));
                        Queue2.emplace(make_pair(NextRow, NextCol));
                        IsVisited[NextRow][NextCol] = true;
                        Sum += Map[NextRow][NextCol];
                    }
                }
            }

            int NumOfUnion = Queue2.size();
            // NumOfUnion이 1이라는 것은 국경이 열리지 않았다는 것
            if (NumOfUnion != 1)
            {
                bIsOpen = true;
                int NewNumOfPerson = Sum / NumOfUnion;
                while (!Queue2.empty())
                {
                    Map[Queue2.front().first][Queue2.front().second] = NewNumOfPerson;
                    Queue2.pop();
                }
            }
        }
    }

    if (bIsOpen)
    {
        ++Answer;
        Solve();
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

    cin >> N >> L >> R;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            cin >> Map[row][col];
        }
    }

    Solve();
    cout << Answer << endl;
}