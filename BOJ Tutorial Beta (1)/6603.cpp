#include <iostream>
#include <vector>
#include <algorithm>

int k;

void Combination(std::vector<int> v, int r)
{
    std::string bitmask;
    for(int i=0; i<r; ++i)
    {
        bitmask += "1";
    }
    bitmask.resize(v.size(),0);;

    do
    {
        for(int i=0; i<v.size(); ++i)
        {
            if(bitmask[i] == '1')
            {
                std::cout << v[i] <<  " ";
            }
        }
        std::cout << '\n';
    }while(prev_permutation(bitmask.begin(),bitmask.end()));
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    while(true)
    {
        std::cin >> k;
        std::cin.clear();
        if(k==0) break;
        std::vector<int> v(k);
        for(int i=0; i<k; ++i)
        {
            std::cin >> v[i];
        }
        Combination(v, 6);
        std::cout << '\n';
    }
    return 0;
}