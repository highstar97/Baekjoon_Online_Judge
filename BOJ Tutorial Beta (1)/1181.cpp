#include <iostream>
#include <algorithm>

int N;
std::string arr[20000];

bool Compare(const std::string &s1, const std::string &s2)
{
    if(s1.length() != s2.length())
    {
        return s1.length() < s2.length();
    }
    else
    {
        return s1 < s2;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i=0; i<N; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr,arr+N,Compare);

    std::cout << arr[0] << '\n';
    for(int i=1; i<N; ++i)
    {
        if(arr[i] != arr[i-1])
            std::cout << arr[i] << '\n';
    }
    return 0;
}