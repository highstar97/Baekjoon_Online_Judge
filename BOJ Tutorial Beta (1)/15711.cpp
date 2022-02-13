#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> v;
bool IsPrime[2000001];

bool isPrimeNumber(long long a)
{
    for (int i = 0; i < (int)v.size() && (long long)v[i] * v[i] <= a; i++)
    {
        if (a % v[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    /* 에라토스테네스의 채 */
    std::fill_n(IsPrime, 2000001, true);
    IsPrime[1] = false;
    for (int i = 2; i * i < 2000001; i++)
    {
        if (IsPrime[i])
        {
            v.emplace_back(i);
            for (int j = i + i; j < 2000001; j += i)
            {
                IsPrime[j] = false;
            }
        }
    }

    int N;
    std::cin >> N;
    while (N--)
    {
        long long a, b;
        std::cin >> a >> b;
        a += b;

        if (a <= 3)
        {
            std::cout << "NO\n";
            continue;
        }
        if (a % 2 == 0)
        {
            std::cout << "YES\n";
            continue;
        }
        a -= 2;
        if (isPrimeNumber(a))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}