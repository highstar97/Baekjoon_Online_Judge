#include <iostream>
#include <algorithm>

int N,M;
int arr[500000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr,arr+N);

    std::cin >> M;
    for(int i=0; i<M; ++i)
    {
        int input;
        std::cin >> input;
        std::cout << std::upper_bound(arr,arr+N,input) - std::lower_bound(arr,arr+N,input) << " ";
    }
    return 0;
}