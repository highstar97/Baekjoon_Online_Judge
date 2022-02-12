#include <iostream>
#include <math.h>

bool IsPrime(int n)
{
    if(n==1) return false;
    if(n==2 || n==3)    return true;
    if(n%6 == 1 || n%6 == 5)
    {
        for(int i=2; i<=sqrt(n); ++i)
        {
            if(n%i == 0)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    while(true)
    {
        bool isSuccess = false;
        int input;
        std::cin >> input;

        if(input == 0)  break;

        for(int i=1; i<input/2; ++i)
        {
            int a = 2*i + 1;
            int b = input - a;
            if(IsPrime(a) && IsPrime(b))
            {
                std::cout << input << " = " << a << " + " << b << "\n";
                isSuccess = true;
                break;
            }
        }
        if(!isSuccess)
        {
            std::cout << "Goldbach's conjecture is wrong\n";
        }
    }
    return 0;
}