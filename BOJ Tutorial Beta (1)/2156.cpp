#include <iostream>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    int wine[N+1];
    int dp[N+1];
    for(int i=1; i<=N; ++i)
    {
        std::cin >> wine[i];
    }

    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for(int i=3; i<=N; ++i)
    {
        dp[i] = std::max(dp[i-3] + wine[i-1] + wine[i], std::max(dp[i-2] + wine[i], dp[i-1]));
    }
    std::cout << dp[N];
}