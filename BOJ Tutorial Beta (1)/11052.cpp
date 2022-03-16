#include <iostream>

int N;
int price[1001];
int dp[1001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> N;
    for(int i=1; i<=N; ++i)
    {
        std::cin >> price[i];
    }

    dp[0] = 0;
    for(int i=1; i<=N; ++i)
    {
        dp[i] = price[i];
        for(int j=1; j<=i/2; ++j)
        {
            dp[i] = std::max(dp[i], dp[j] + dp[i-j]);
        }
    }
    std::cout << dp[N];
}