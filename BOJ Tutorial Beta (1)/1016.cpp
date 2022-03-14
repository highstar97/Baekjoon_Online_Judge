#include <iostream>

long long Min, Max;
long long num[1000001];

int main()
{
    int answer = 0;
    std::cin >> Min >> Max;

    for (long long i = 2; i * i <= Max; ++i)
    {
        long long n = Min / (i * i);

        if (Min % (i * i))
            ++n;

        while (n * i * i <= Max)
        {
            num[n * i * i - Min] = 1;
            ++n;
        }
    }

    for(int i=0; i<=Max-Min; ++i)
    {
        if(num[i] == 0)
            ++answer;
    }
    std::cout << answer;
}