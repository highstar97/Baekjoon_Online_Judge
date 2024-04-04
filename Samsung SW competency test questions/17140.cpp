#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define max(a, b) a > b ? a : b

using namespace std;

int R, C, K, Answer;
int MaxRow = 3, MaxCol = 3;
int Count[MAX];
int Map[MAX][MAX];

/*void Print()
{
    cout << "-----------------------------\n";
    for(int row=0; row<MaxRow; ++row)
    {
        for(int col=0; col<MaxCol; ++col)
        {
            cout << Map[row][col] << " ";
        }
        cout << '\n';
    }
    cout << "-----------------------------\n";
}*/

void FuncR()
{
    for (int row = 0; row < MaxRow; ++row)
    {
        vector<pair<int, int>> Vec;
        // Count 초기화
        for (int i = 0; i < MAX; ++i)
        {
            Count[i] = 0;
        }

        for (int col = 0; col < MaxCol; ++col)
        {
            ++Count[Map[row][col]];
        }

        for (int i = 1; i < MAX; ++i)
        {
            if (Count[i] == 0)
                continue;

            Vec.emplace_back(make_pair(Count[i], i));
        }

        sort(Vec.begin(), Vec.end());

        // Map[row] 0으로 초기화
        for (int col = 0; col < MaxCol; ++col)
        {
            Map[row][col] = 0;
        }

        for (int i = 0; i < Vec.size(); ++i)
        {
            Map[row][i * 2] = Vec[i].second;
            Map[row][i * 2 + 1] = Vec[i].first;
        }

        MaxCol = max(MaxCol, Vec.size() * 2);
    }
}

void FuncC()
{
    for (int col = 0; col < MaxCol; ++col)
    {
        vector<pair<int, int>> Vec;
        // Count 초기화
        for (int i = 0; i < MAX; ++i)
        {
            Count[i] = 0;
        }

        for (int row = 0; row < MaxRow; ++row)
        {
            ++Count[Map[row][col]];
        }

        for (int i = 1; i < MAX; ++i)
        {
            if (Count[i] == 0)
                continue;

            Vec.emplace_back(make_pair(Count[i], i));
        }

        sort(Vec.begin(), Vec.end());

        // Map[][col] 0으로 초기화
        for (int row = 0; row < MaxRow; ++row)
        {
            Map[row][col] = 0;
        }

        for (int i = 0; i < Vec.size(); ++i)
        {
            Map[i * 2][col] = Vec[i].second;
            Map[i * 2 + 1][col] = Vec[i].first;
        }

        MaxRow = max(MaxRow, Vec.size() * 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> K;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            cin >> Map[row][col];
        }
    }

    while (!(Map[R - 1][C - 1] == K))
    {
        if (Answer > 100)
        {
            cout << -1 << endl;
            return 0;
        }

        // R연산 or C연산
        if (MaxRow >= MaxCol)
        {
            FuncR();
        }
        else
        {
            FuncC();
        }
        ++Answer;
    }
    cout << Answer << endl;
}