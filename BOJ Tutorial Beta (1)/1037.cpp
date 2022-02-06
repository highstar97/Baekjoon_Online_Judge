#include <iostream>
#include <algorithm>

int N;

int main()
{
    std::cin >> N;
    int arr[N];
    for(int i=0; i<N; ++i)
    {
        std::cin >> arr[i];
    }
    std::sort(arr,arr+N);

    std::cout << arr[0] * arr[N-1];
    return 0;
}