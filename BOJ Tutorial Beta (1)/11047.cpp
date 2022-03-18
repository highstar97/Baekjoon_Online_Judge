#include <iostream>

int N, K;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> N >> K;
    int answer = 0;
    int coin[N];

    for(int i=0; i<N; ++i)
    {
        std::cin >> coin[i];
    }

    for(int i=N-1; i>=0; --i)
    {
        int m = K / coin[i];
        K -= coin[i] * m;
        answer += m;
    }

    std::cout << answer;
}