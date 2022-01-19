// map을 이용한 숏 코딩
#include <iostream>
#include <map>

int N,M;
std::map<int,int> m;

int main()
{
    std::cin.tie(0);
    std::cin>>N;
    while(N--)
    {
        std::cin >> M;
        m[M] = 1;
    }
    std::cin>>M;
    while(M--)
    {
        if(std::cin >> N)
            std::cout <<m[N] << "\n";
    }

    std::cout << m[3];
}

// Binary Search를 이용한 풀이
/*
#include <iostream>
#include <algorithm>

int N,M;

void Binary_Search(int target, int arr[])
{
    int low = 0;
    int high = N-1;
    int mid;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(arr[mid] == target)
        {
            std::cout << 1 << '\n';
            return ;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    std::cout << 0 << '\n';
    return ;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    int arr[N];

    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr,arr+N);
    std::cin >> M;
    for(int i=0; i<M; i++)
    {
        int target;
        std::cin >> target;
        Binary_Search(target, arr);
    }

    return 0;
}
*/