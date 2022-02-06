#include <iostream>

int N;
int answer = 0;
bool IsPrime[1001];

void Sieve_of_Eratosthenes(int Max)
{
    std::fill_n(IsPrime,1001,true);
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i=2; i<Max; ++i)
    {
        if(IsPrime[i] == true)
        {
            for(int j=2*i; j<Max; j+=i)
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

    Sieve_of_Eratosthenes(1001);

    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        int input;
        std::cin >> input;
        if(IsPrime[input] == true)
        {
            answer++;
        } 
    }

    std::cout << answer;
    return 0;
}