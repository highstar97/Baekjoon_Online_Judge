#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Answer;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Board[500][500];
bool IsVisited[500][500];

void DFS(int Depth, pair<int, int> Point, int Sum)
{
    if (Depth == 4)
    {
        Answer = max(Answer, Sum);
        return;
    }

    Sum += Board[Point.first][Point.second];
    IsVisited[Point.first][Point.second] = true;

    for (int k = 0; k < 4; ++k)
    {
        int NextRow = Point.first + drow[k];
        int NextCol = Point.second + dcol[k];

        if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= M)
            continue;

        if (IsVisited[NextRow][NextCol])
            continue;

        DFS(Depth + 1, {NextRow, NextCol}, Sum);
    }
    IsVisited[Point.first][Point.second] = false;
}

void Shape1(int r, int c)
{
    int Sum = 0;
    Sum = Board[r][c] + Board[r][c + 1] + Board[r][c + 2] + Board[r - 1][c + 1];
    Answer = max(Answer, Sum);
}

void Shape2(int r, int c)
{
    int Sum = 0;
    Sum = Board[r][c] + Board[r][c + 1] + Board[r][c + 2] + Board[r + 1][c + 1];
    Answer = max(Answer, Sum);
}

void Shape3(int r, int c)
{
    int Sum = 0;
    Sum = Board[r][c] + Board[r + 1][c] + Board[r + 2][c] + Board[r + 1][c + 1];
    Answer = max(Answer, Sum);
}

void Shape4(int r, int c)
{
    int Sum = 0;
    Sum = Board[r][c] + Board[r - 1][c + 1] + Board[r][c + 1] + Board[r + 1][c + 1];
    Answer = max(Answer, Sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int Row = 0; Row < N; ++Row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> Board[Row][col];
        }
    }

    for (int Row = 0; Row < N; ++Row)
    {
        for (int Col = 0; Col < M; ++Col)
        {
            DFS(0, {Row, Col}, 0);
            // ㅗ ㅏ ㅜ ㅓ 모양에 대해서 각각 체크 필요
            if (Row - 1 >= 0 && Col + 2 < M)
                Shape1(Row, Col);
            if (Col + 2 < M && Row + 1 < N)
                Shape2(Row, Col);
            if (Row + 2 < N && Col + 1 < M)
                Shape3(Row, Col);
            if (Row + 1 < N && Row - 1 >= 0 && Col + 1 < M)
                Shape4(Row, Col);
        }
    }

    cout << Answer << endl;
}