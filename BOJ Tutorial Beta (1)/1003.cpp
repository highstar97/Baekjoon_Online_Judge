#include <iostream>

using ii = std::pair<int,int>;

int N;
ii data[41];

int main()
{
    data[0] = std::make_pair(1,0);
    data[1] = std::make_pair(0,1);
    for(int i=2; i<41; ++i)
    {
        data[i] = std::make_pair(data[i-1].first + data[i-2].first, data[i-1].second + data[i-2].second);
    }
    std::cin >> N;
    while(N--)
    {
        int input;
        std::cin >> input;
        std::cout << data[input].first << " " << data[input].second << '\n';
    }
}