#include <iostream>

int N;
int answer = 0;
int num[1001];
int dp[1001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    for(int i=1; i<=N; ++i)
    {
        std::cin >> num[i];
        dp[i] = 0;
    }

    dp[0] = 0;
    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<=i-1; ++j)
        {
            if(num[j] < num[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
            answer = std::max(answer,dp[i]);
        }
    }

    std::cout << answer;
}