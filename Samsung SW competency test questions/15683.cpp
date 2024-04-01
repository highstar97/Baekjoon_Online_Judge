#include <iostream>
#include <vector>

using namespace std;

int N, M;
int Answer = 1e9;
int drow[4] = {-1, 0, 1, 0}; // 상 우 하 좌
int dcol[4] = {0, 1, 0, -1};
int Map[8][8];

struct Camera
{
    int Row;
    int Col;
    int Number;
    int Dir;
};

void MakeLine(int Row, int Col, int Dir, vector<vector<int>> &TempMap)
{
    while (true)
    {
        int NextRow = Row + drow[Dir % 4];
        int NextCol = Col + dcol[Dir % 4];

        if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= M)
            break;

        if (TempMap[NextRow][NextCol] == 6)
            break;

        TempMap[NextRow][NextCol] = -1;
        Row = NextRow;
        Col = NextCol;
    }
}

void Calculate(vector<Camera> &Cameras)
{
    vector<vector<int>> TempMap(N, vector<int>(M, 0));
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            TempMap[row][col] = Map[row][col];
        }
    }

    for (Camera Camera : Cameras)
    {
        int Row = Camera.Row;
        int Col = Camera.Col;
        int Dir = Camera.Dir;
        if (Camera.Number == 1)
        {
            MakeLine(Row, Col, Dir, TempMap);
        }
        else if (Camera.Number == 2)
        {
            MakeLine(Row, Col, Dir, TempMap);
            MakeLine(Row, Col, Dir + 2, TempMap);
        }
        else if (Camera.Number == 3)
        {
            MakeLine(Row, Col, Dir, TempMap);
            MakeLine(Row, Col, Dir + 1, TempMap);
        }
        else if (Camera.Number == 4)
        {
            MakeLine(Row, Col, Dir, TempMap);
            MakeLine(Row, Col, Dir + 1, TempMap);
            MakeLine(Row, Col, Dir + 2, TempMap);
        }
        else
        {
            MakeLine(Row, Col, Dir, TempMap);
            MakeLine(Row, Col, Dir + 1, TempMap);
            MakeLine(Row, Col, Dir + 2, TempMap);
            MakeLine(Row, Col, Dir + 3, TempMap);
        }
    }

    int Sum = 0;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            if (TempMap[row][col] == 0)
            {
                ++Sum;
            }
        }
    }

    Answer = min(Answer, Sum);
}

void Solve(int Depth, vector<Camera> Cameras)
{
    if (Depth == Cameras.size())
    {
        Calculate(Cameras);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        // 5번 카메라는 회전 의미 없음
        if (Cameras[Depth].Number == 5)
        {
            Solve(Depth + 1, Cameras);
        }
        else
        {
            Cameras[Depth].Dir = i;
            Solve(Depth + 1, Cameras);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Camera> Cameras;

    cin >> N >> M;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> Map[row][col];
            if (Map[row][col] != 0 && Map[row][col] != 6)
            {
                Cameras.emplace_back(Camera{row, col, Map[row][col], 0});
            }
        }
    }

    Solve(0, Cameras);
    cout << Answer << endl;
}