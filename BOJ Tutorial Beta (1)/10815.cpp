#include <iostream>
#include <algorithm>

int N, M;
int arr[500000];

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

    std::cin >> M;
    while(M--)
    {
        int target;
        std::cin >> target;
        if(std::binary_search(arr, arr+N, target))
        {
            std::cout << 1 << " ";
        }
        else
        {
            std::cout << 0 << " ";
        }
    }

    return 0;
}