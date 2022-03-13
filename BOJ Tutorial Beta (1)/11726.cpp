#include <iostream>

int N;
int d[10001];

int Function(int n)
{
    for (int i = 3; i <= n; ++i)
    {
        d[i] = (d[i - 2] + d[i - 1]) % 10007;
    }
    return d[n];
}

int main()
{
    std::cin >> N;
    d[1] = 1;
    d[2] = 2;
    std::cout << Function(N);
}