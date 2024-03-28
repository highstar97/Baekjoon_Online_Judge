#include <iostream>
#define MAX 101
using namespace std;

int N, K;
int DP[101][100001];
pair<int, int> Data[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        int w, v;
        cin >> w >> v;
        Data[i] = {w, v};
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j <= K; ++j)
        {
            if (j >= Data[i].first)
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Data[i].first] + Data[i].second);
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    cout << DP[N][K];
}