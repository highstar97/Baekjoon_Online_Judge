#include <iostream>
#include <vector>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> N;
    std::vector<std::vector<int>> v(N,std::vector<int>());
    std::vector<std::vector<int>> sum(N,std::vector<int>());
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<i+1; ++j)
        {
            int input;
            std::cin >> input;
            v[i].emplace_back(input);
            sum[i].emplace_back(0);
        }
    }

    sum[0][0] = v[0][0];
    for(int i=1; i<N; ++i)
    {
        sum[i][0] = sum[i-1][0] + v[i][0];
        for(int j=1; j<i; ++j)
        {
            sum[i][j] = std::max(sum[i-1][j-1],sum[i-1][j]) + v[i][j];
        }
        sum[i][i] = sum[i-1][i-1] + v[i][i];
    }

    int answer = -1;
    for(auto data : sum[N-1])
    {
        answer < data ? answer = data : answer;
    }
    std::cout << answer;
}