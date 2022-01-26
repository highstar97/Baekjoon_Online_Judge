#include <iostream>
#include <algorithm>

using location = std::pair<int,int>;
// typedef std::pair<int,int> location;

int N;
location arr[100000];

bool Compare(const location& lb, const location lf)
{
    if(lb.first == lf.first)
    {
        return lb.second < lf.second;
    }
    else
    {
        return lb.first < lf.first;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        int x,y;
        std::cin >> x >> y;
        arr[i] = std::make_pair(x,y);
    }

    std::sort(arr,arr+N,Compare);

    for(int i=0; i<N; i++)
    {
        std::cout << arr[i].first << " " << arr[i].second << '\n';
    }
    return 0;
}