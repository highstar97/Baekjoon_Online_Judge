#include <iostream>
#include <algorithm>

int N, M;

void Permutation(int arr[], int r)
{
    std::sort(arr,arr+N);

    do
    {
        for(int i=0; i<r; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
        std::reverse(arr+r,arr+N);
    }while(std::next_permutation(arr,arr+N));
}

int main()
{
    std::cin >> N >> M;
    int arr[N];
    for(int i=0; i<N; ++i)
    {
        arr[i] = i+1;
    }
    Permutation(arr,M);
    return 0;
}