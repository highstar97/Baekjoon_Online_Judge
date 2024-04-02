#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, Answer; // N : 정사각 맵의 길이, M : 나무의 수, K : K년 후, Answer : K년 후 살아있는 나무의 수
int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Power[11][11];       // 맵에 저장되어 있는 양분의 값
vector<int> Map[11][11]; // 맵에 있는 나무의 나이들
int A[11][11];           // 겨울에 추가되는 양분의 값

void AfterYear()
{
    // Spring
    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            if (Map[row][col].size() == 0)
                continue;

            int DeadTreeEnergy = 0;
            vector<int> Temp;
            sort(Map[row][col].begin(), Map[row][col].end());

            for (int i = 0; i < Map[row][col].size(); ++i)
            {
                int Age = Map[row][col][i];

                if (Power[row][col] >= Age)
                {
                    Power[row][col] -= Age;
                    Temp.emplace_back(Age + 1);
                }
                else
                {
                    DeadTreeEnergy += (Age / 2);
                }
            }

            Map[row][col].clear();

            for (int i = 0; i < Temp.size(); ++i)
            {
                Map[row][col].emplace_back(Temp[i]);
            }

            // Summer
            Power[row][col] += DeadTreeEnergy;
        }
    }

    // Autumn
    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            if (Map[row][col].size() == 0)
                continue;

            for (int i = 0; i < Map[row][col].size(); ++i)
            {
                if ((Map[row][col][i] % 5) != 0)
                    continue;

                for (int k = 0; k < 8; ++k)
                {
                    int NextRow = row + drow[k];
                    int NextCol = col + dcol[k];

                    if (NextRow <= 0 || NextRow > N || NextCol <= 0 || NextCol > N)
                        continue;

                    Map[NextRow][NextCol].emplace_back(1);
                }
            }
        }
    }

    // Winter
    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            Power[row][col] += A[row][col];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            cin >> A[row][col];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        Map[x][y].emplace_back(c);
    }

    // 기본 양분 5씩
    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            Power[row][col] = 5;
        }
    }

    while (K--)
    {
        AfterYear();
    }

    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            Answer += Map[row][col].size();
        }
    }
    cout << Answer << endl;
}