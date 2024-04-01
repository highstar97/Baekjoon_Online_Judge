#include <iostream>
#include <vector>

#define MAX 101
using namespace std;

int K, x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int Map[101][101];
vector<int> Dir;

void MakeDragonCurve()
{
    for (int i = Dir.size() - 1; i >= 0; --i)
    {
        int NextDir = (Dir[i] + 1) % 4;
        x += dx[NextDir];
        y += dy[NextDir];
        Map[y][x] = 1;

        Dir.emplace_back(NextDir);
    }
}

void CountSquare()
{
    int Answer = 0;
    for (int i = 0; i < MAX - 1; ++i)
    {
        for (int j = 0; j < MAX - 1; ++j)
        {
            if (Map[i][j] == 1 && Map[i + 1][j] == 1 && Map[i][j + 1] == 1 && Map[i + 1][j + 1] == 1)
            {
                ++Answer;
            }
        }
    }
    cout << Answer << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int d, g;
        cin >> x >> y >> d >> g;

        Dir.clear();
        Map[y][x] = 1;
        x += dx[d];
        y += dy[d];
        Map[y][x] = 1;

        Dir.emplace_back(d);
        for (int j = 0; j < g; ++j)
        {
            MakeDragonCurve();
        }
    }

    CountSquare();
}