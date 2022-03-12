#include <iostream>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    int a[N+1][3] = {0};
    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            std::cin >> a[i][j];
        }
    }

    int d[N+1][3] = {0};
    for(int i=1; i<=N; ++i)
    {
        d[i][0] = std::min(d[i-1][1],d[i-1][2]) + a[i][0];
        d[i][1] = std::min(d[i-1][0],d[i-1][2]) + a[i][1];
        d[i][2] = std::min(d[i-1][0],d[i-1][1]) + a[i][2];
    }

    std::cout << std::min(d[N][0],std::min(d[N][1],d[N][2]));
    return 0;
}