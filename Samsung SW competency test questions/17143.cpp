#include <iostream>

using namespace std;

struct Shark
{
    int speed;
    int dir;
    int size;

    Shark()
    {
        speed = 0;
        dir = 0;
        size = 0;
    }

    Shark(int s, int d, int z)
    {
        speed = s;
        dir = d;
        size = z;
    }
};

int R, C, M, Answer;
int drow[4] = {-1, 1, 0, 0}; // 위 아래 오른 왼
int dcol[4] = {0, 0, 1, -1};
Shark Map[101][101];

/*void Print()
{
    cout << "---------------------------\n";
    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            cout << Map[row][col].size << " ";
        }
        cout << "\n";
    }
    cout << "---------------------------\n";
}*/

void Catch(int col)
{
    // 행에 있는 row가 가장 낮은 Shark 제거
    for (int row = 1; row <= R; ++row)
    {
        if (Map[row][col].size > 0)
        {
            Answer += Map[row][col].size;
            Map[row][col] = Shark();
            return;
        }
    }
}

void Copy(Shark TargetMap[][101], Shark BaseMap[][101])
{
    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            TargetMap[row][col] = BaseMap[row][col];
        }
    }
}

void Move()
{
    Shark CopyMap[101][101];
    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            if (Map[row][col].size == 0)
                continue;

            // 이동
            Shark CurrentShark = Map[row][col];
            Map[row][col] = Shark();
            int CurrentRow = row;
            int CurrentCol = col;
            int Try = CurrentShark.speed % (CurrentShark.dir == 0 || CurrentShark.dir == 1 ? 2 * (R - 1) : 2 * (C - 1));
            for (int i = 0; i < Try; ++i)
            {
                int NextRow = CurrentRow + drow[CurrentShark.dir];
                int NextCol = CurrentCol + dcol[CurrentShark.dir];

                // 벽에 부딛히면 방향 전환
                if (NextRow < 1 || NextRow > R || NextCol < 1 || NextCol > C)
                {
                    if (CurrentShark.dir == 0 || CurrentShark.dir == 2)
                    {
                        CurrentShark.dir += 1;
                    }
                    else
                    {
                        CurrentShark.dir -= 1;
                    }
                    NextRow = CurrentRow + drow[CurrentShark.dir];
                    NextCol = CurrentCol + dcol[CurrentShark.dir];
                }

                CurrentRow = NextRow;
                CurrentCol = NextCol;
            }

            // CopyMap에 나보다 사이즈가 큰 상어가 있는 경우는 큰 상어가 살아남음
            if (CopyMap[CurrentRow][CurrentCol].size < CurrentShark.size) // 같은 크기는 주어지지 않음
            {
                CopyMap[CurrentRow][CurrentCol] = CurrentShark;
            }
        }
    }
    Copy(Map, CopyMap);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;
    for (int i = 0; i < M; ++i)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Map[r][c] = Shark(s, d - 1, z);
    }

    for (int col = 1; col <= C; ++col)
    {
        Catch(col);
        Move();
    }

    cout << Answer << endl;
}