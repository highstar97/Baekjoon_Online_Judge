#include <iostream>
#include <math.h>

int N, sum;
int answer = 0;
bool IsPrime[4000001];

void Sieve_of_Eratosthenes(int Max)
{
    std::fill_n(IsPrime,4000001,true);
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i=2; i<=Max; ++i)
    {
        if(IsPrime[i])
        {
            for(int j=i*2; j<=Max;j+=i)
            {
                IsPrime[j] = false;
            }
        }
    }
}

int main()
{
    std::cin >> N;
    
    Sieve_of_Eratosthenes(N);

    for(int i=2; i<=N; ++i)
    {
        sum = 0;
        for(int j=i; j<=N; ++j)
        {
            if(!IsPrime[i]) // 합성수부터 시작했을때 정답 겹침 방지
            {
                break;
            }
            if(IsPrime[j])
            {
                sum += j;
                if(sum == N)
                {
                    answer++;
                }
                else if(sum > N)
                {
                    break;
                }
            }
        }
    }

    std::cout << answer;
    return 0;
}