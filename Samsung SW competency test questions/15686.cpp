#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

using namespace std;

int N, M;
int Answer = 1e9;
int Map[50][50];
vector<pair<int, int>> Homes;
vector<pair<int, int>> Chickens;
vector<bool> IsRemoved(13);

void Calculate()
{
    int SumOfChickenDistance = 0;
    for (int i = 0; i < Homes.size(); ++i)
    {
        int ChickenDistance = 1e9;
        for (int j = 0; j < Chickens.size(); ++j)
        {
            if (IsRemoved[j] == true)
            {
                continue;
            }

            ChickenDistance = min(ChickenDistance, abs(Homes[i].first - Chickens[j].first) + abs(Homes[i].second - Chickens[j].second));
        }
        SumOfChickenDistance += ChickenDistance;
    }

    Answer = min(Answer, SumOfChickenDistance);
}

void BT(int Index, int Depth)
{
    if (Depth == Chickens.size() - M)
    {
        Calculate();
        return;
    }

    for (int i = Index; i < Chickens.size(); ++i)
    {
        if (IsRemoved[i] == true)
            continue;

        IsRemoved[i] = true;
        BT(i, Depth + 1);
        IsRemoved[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            cin >> Map[row][col];
            if (Map[row][col] == 1)
            {
                Homes.emplace_back(make_pair(row, col));
            }
            if (Map[row][col] == 2)
            {
                Chickens.emplace_back(make_pair(row, col));
            }
        }
    }

    BT(0, 0);

    cout << Answer << endl;
}