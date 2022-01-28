#include <iostream>
#include <algorithm>

using Location = std::pair<int,int>;

int N;
Location arr[100000];

bool Compare(const Location& lb, const Location& lf)
{
    if(lb.second == lf.second)
    {
        return lb.first < lf.first;
    }
    else
    {
        return lb.second < lf.second;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i=0; i<N; ++i)
    {
        std::cin >> arr[i].first >> arr[i].second;
    }

    std::sort(arr,arr+N,Compare);

    for(int i=0; i<N; ++i)
    {
        std::cout << arr[i].first << " " << arr[i].second << '\n';
    }
    return 0;
} 