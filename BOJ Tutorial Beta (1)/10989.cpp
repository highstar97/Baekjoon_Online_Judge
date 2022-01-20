#include <iostream>
#include <map>

int N;
std::map<int,int> m;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    while(N--)
    {
        int input;
        std::cin >> input;
        m[input]++;
    }

    for(auto data : m)
    {
        while(data.second--)
        {
            std::cout << data.first << '\n';
        }
    }

    return 0;    
}