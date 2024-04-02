#include <iostream>

using namespace std;

int R, C, T, Answer;
pair<int, int> AirCleaner1, AirCleaner2;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Map[51][51];
int CopyMap[51][51];

void Copy(int Map1[][51], int Map2[][51])
{
    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            Map1[row][col] = Map2[row][col];
        }
    }
}

void Run()
{
    Copy(CopyMap, Map);
    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            if (Map[row][col] == 0 || Map[row][col] == -1)
                continue;

            int CanExpanse = 0;
            int ExpanseValue = Map[row][col] / 5;
            for (int k = 0; k < 4; ++k)
            {
                int NextRow = row + drow[k];
                int NextCol = col + dcol[k];

                if (NextRow < 1 || NextRow > R || NextCol < 1 || NextCol > C)
                    continue;

                if (Map[NextRow][NextCol] == -1)
                    continue;

                CopyMap[NextRow][NextCol] += ExpanseValue;
                ++CanExpanse;
            }
            CopyMap[row][col] -= CanExpanse * ExpanseValue;
        }
    }
    Copy(Map, CopyMap);

    // 위쪽 공기청정기
    for (int row = AirCleaner1.first - 1; row > 1; --row)
    {
        Map[row][1] = Map[row - 1][1];
    }
    for (int col = 1; col < C; ++col)
    {
        Map[1][col] = Map[1][col + 1];
    }
    for (int row = 1; row < AirCleaner1.first; ++row)
    {
        Map[row][C] = Map[row + 1][C];
    }
    for (int col = C; col > 2; --col)
    {
        Map[AirCleaner1.first][col] = Map[AirCleaner1.first][col - 1];
    }
    Map[AirCleaner1.first][2] = 0;
    // 아래쪽 공기청정기
    for (int row = AirCleaner2.first + 1; row < R; ++row)
    {
        Map[row][1] = Map[row + 1][1];
    }
    for (int col = 1; col < C; ++col)
    {
        Map[R][col] = Map[R][col + 1];
    }
    for (int row = R; row > AirCleaner2.first; --row)
    {
        Map[row][C] = Map[row - 1][C];
    }
    for (int col = C; col > 2; --col)
    {
        Map[AirCleaner2.first][col] = Map[AirCleaner2.first][col - 1];
    }
    Map[AirCleaner2.first][2] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            cin >> Map[row][col];
            if (Map[row][col] == -1)
            {
                AirCleaner1.first = row - 1;
                AirCleaner1.second = col;
                AirCleaner2.first = row;
                AirCleaner1.second = col;
            }
        }
    }

    while (T--)
    {
        Run();
    }

    for (int row = 1; row <= R; ++row)
    {
        for (int col = 1; col <= C; ++col)
        {
            if (Map[row][col] == 0 || Map[row][col] == -1)
                continue;

            Answer += Map[row][col];
        }
    }
    cout << Answer << endl;
}