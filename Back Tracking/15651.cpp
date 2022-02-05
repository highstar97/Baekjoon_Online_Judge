#include <iostream>
#include <vector>

int N, M;
std::vector<int> v;

void Function(std::vector<int> v, int depth)
{
    if(depth == M+1)
    {
        for(auto data : v)
        {
            std::cout << data << " ";
        }
        std::cout << '\n';
        return;
    }

    for(int i=1; i<=N; ++i)
    {
        std::vector<int> next_v = v;
        next_v.emplace_back(i);
        Function(next_v,depth+1);
    }
}

int main()
{
    std::cin >> N >> M;
    Function(v,1);
    return 0;
}