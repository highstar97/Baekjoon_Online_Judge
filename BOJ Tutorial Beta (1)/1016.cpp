#include <iostream>
#include <vector>
#include <math.h>

long long min, max;

int main()
{
    std::cin >> min >> max;

    int Total = max - min + 1;

    std::vector<bool> oo(max-min+1,false);

    for(int i=2; i*i <= max; ++i)
    { 
        long long square = i*i;
        long long num = square;

        while(num < min)
        {
            num += square;
        }
        for(long long j=num; j<=max; j+=square)
        {
            if(oo[j] == false)
            {
                oo[j] = true;
                Total--;
            }
        }
    }
    std::cout << Total;
    return 0;
}