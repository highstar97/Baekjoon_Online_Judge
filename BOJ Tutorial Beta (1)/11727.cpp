#include <iostream>

int N;
int d[1001];

int Function(int n)
{
    for (int i = 3; i <= n; ++i)
    {
        d[i] = (d[i - 1] + d[i - 2] + d[i - 2]) % 10007;
    }
    return d[n];
}

int main()
{
    std::cin >> N;

    d[1] = 1;
    d[2] = 3;
    std::cout << Function(N);
}