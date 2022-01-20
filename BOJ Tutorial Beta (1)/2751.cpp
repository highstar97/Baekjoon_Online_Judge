#include <iostream>
#include <algorithm>

int N;
int arr[1000000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr,arr+N);

    for(int i=0; i<N; i++)
    {
        std::cout << arr[i] << '\n';
    }

    return 0;    
}