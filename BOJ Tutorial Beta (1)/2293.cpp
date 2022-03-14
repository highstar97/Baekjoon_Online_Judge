#include <iostream>

int N, K;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;
    int num[N];
    int dp[K+1] ={0};
    for (int i = 0; i < N; ++i)
    {
        std::cin >> num[i];
    }

    dp[0] = 1;
    for(int i=0; i<N;++i)
    {
        for(int j=num[i]; j<= K; ++j)
        {
            dp[j] += dp[j-num[i]];
        }
    }

    std::cout << dp[K];
}