#include <iostream>
#define INF 1e9
#define MAX 101
using namespace std;

int N, K, Answer;
int Money[MAX];
int Dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> Money[i];
    }

    fill(Dp + 1, Dp + K+1, INF); // { 0, INF, INF, INF, ... }

    for (int i = 0; i < N; ++i)
    {
        for (int j = Money[i]; j <= K; ++j)
        {
            Dp[j] = min(Dp[j], Dp[j - Money[i]] + 1);
        }
    }
    
    Dp[K] == INF ? cout << "-1" : cout << Dp[K];
}