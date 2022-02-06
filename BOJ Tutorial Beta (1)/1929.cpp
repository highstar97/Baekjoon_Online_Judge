#include <iostream>

int M, N;
bool IsPrime[1000001];

void Sieve_of_Eratosthenes(int Max)
{
    std::fill_n(IsPrime,Max+1,true);
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(int i=2; i<=Max; ++i)
    {
        if(IsPrime[i] == true)
        {
            for(int j=2*i; j<=Max; j+=i)
            {
                IsPrime[j] = false;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> M >> N;
    Sieve_of_Eratosthenes(N);
    
    for(int i=M; i<=N; ++i)
    {
        if(IsPrime[i])
        {
            std::cout << i << '\n';
        }
    }
}