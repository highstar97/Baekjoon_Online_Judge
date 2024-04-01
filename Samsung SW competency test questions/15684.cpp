#include <iostream>
#include <vector>
#define min(a, b) a < b ? a : b

using namespace std;

int N, M, H;
int Answer = 1e9;
bool Line[31][11];

bool IsSuccess()
{
    for (int col = 1; col <= N; ++col)
    {
        int CurrentCol = col;
        for (int row = 1; row <= H; ++row)
        {
            // 현재 Col에 대해서 왼쪽 사다리가 있는 경우
            if (CurrentCol > 1 && Line[row][CurrentCol - 1])
            {
                CurrentCol -= 1;
            }
            // 현재 Col에 대해서 오른쪽 사다리가 있는 경우
            else if (CurrentCol < N && Line[row][CurrentCol])
            {
                CurrentCol += 1;
            }
        }
        if (col != CurrentCol)
        {
            return false;
        }
    }
    return true;
}

void Solve(int Depth, int Row)
{
    if (Depth > 3)
    {
        return;
    }

    if (IsSuccess())
    {
        Answer = min(Answer, Depth);
        return;
    }

    for (int row = Row; row <= H; ++row)
    {
        for (int col = 1; col < N; ++col)
        {
            if (Line[row][col] == true)
                continue;
            // 왼쪽에 사다리가 있으면 안됨
            if (col - 1 >= 1 && Line[row][col - 1] == true)
            //    continue;
            // 오른쪽에 사다리가 있으면 안됨
            if (col + 1 < N && Line[row][col + 1] == true)
                continue;

            Line[row][col] = true;
            Solve(Depth + 1, row);
            Line[row][col] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        Line[a][b] = true;
    }

    Solve(0, 1);

    if (Answer > 3)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << Answer << endl;
    }
}