#include <iostream>

int N, M;

int GCD(int N, int M)
{
    if(N < M)
    {
        int temp = N;
        N = M;
        M = temp;
    }
    
    if(M == 0)
    {
        return N;
    }
    else
    {
        return GCD(N, N%M);
    }
}

int main()
{
    std::cin >> N >> M;
    int gcd = GCD(N,M);
    std::cout << gcd << '\n' << N*M/gcd;
    return 0;
}