#include <iostream>
#include <set>

int N;
std::set<int> s;

int main()
{
    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        int input;
        std::cin >> input;
        s.emplace(input); 
    }

    for(auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}