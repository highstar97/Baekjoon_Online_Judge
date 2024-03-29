#include <iostream>

#define MAX 50
using namespace std;

int N, M, X, Y, Dir, Answer;
int drow[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dcol[4] = {0, 1, 0, -1};
int Room[MAX][MAX];

int CheckNextDir(int Row, int Col, int Dir)
{
    for (int k = 1; k <= 4; ++k)
    {
        int NextDir = (Dir - k) >= 0 ? Dir - k : Dir - k + 4;
        int NextRow = Row + drow[NextDir];
        int NextCol = Col + dcol[NextDir];

        if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= M)
            continue;

        if (Room[NextRow][NextCol] == 0)
        {
            return NextDir;
        }
    }
    return -1;
}

void DFS(int Row, int Col, int Dir)
{
    // 현재 칸이 청소되지 않은 경우 -> 청소
    if (Room[Row][Col] == 0)
    {
        ++Answer;
    }
    Room[Row][Col] = 2; // 0 : 청소 필요 | 1 : 벽 | 2 : 청소 완료

    // 현재 칸 주변 4칸 중 청소가 필요한 칸이 없는 경우 -> 후진 확인 or 작동 멈춤
    int NextDir = CheckNextDir(Row, Col, Dir); // 반시계 방향으로 4번 회전하면서 체크
    if (NextDir == -1)                         // NextDir == -1 : 청소 필요 없음
    {
        int BackDir = (Dir + 2) % 4;
        int BackRow = Row + drow[BackDir];
        int BackCol = Col + dcol[BackDir];

        // 뒤가 벽 or 범위 밖 종료
        if (Room[BackRow][BackCol] == 1 || BackRow < 0 || BackRow >= N || BackCol < 0 || BackCol >= M)
        {
            cout << Answer << endl;
            exit(0);
        }
        else // 뒤가 청소한 곳
        {
            DFS(BackRow, BackCol, Dir);
        }
    }
    else
    {
        DFS(Row + drow[NextDir], Col + dcol[NextDir], NextDir);
    }
}

int main()
{
    cin >> N >> M;
    cin >> X >> Y >> Dir;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> Room[row][col];
        }
    }

    DFS(X, Y, Dir);
}