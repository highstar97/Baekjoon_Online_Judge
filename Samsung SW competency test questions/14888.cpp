#include <iostream>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

using namespace std;

int N;
int Min = 1e9;
int Max = -1e9;
int Num[11];

void BT(int Index, int Sum, int Cal[])
{
    if (Cal[0] == 0 && Cal[1] == 0 && Cal[2] == 0 && Cal[3] == 0)
    {
        Min = min(Min, Sum);
        Max = max(Max, Sum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (Cal[i] == 0)
        {
            continue;
        }

        --Cal[i];
        switch (i)
        {
        case (0):
        {
            BT(Index + 1, Sum + Num[Index], Cal);
            break;
        }
        case (1):
        {
            BT(Index + 1, Sum - Num[Index], Cal);
            break;
        }
        case (2):
        {
            BT(Index + 1, Sum * Num[Index], Cal);
            break;
        }
        case (3):
        {
            BT(Index + 1, Sum / Num[Index], Cal);
            break;
        }
        }
        ++Cal[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Cal[4];
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    for (int i = 0; i < 4; ++i)
    {
        cin >> Cal[i];
    }

    BT(1, Num[0], Cal);
    cout << Max << '\n'
         << Min;
}