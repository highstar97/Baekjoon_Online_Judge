#include <iostream>
#include <vector>
#include <algorithm>

int N, K;

int Binary_search(int start, int end, std::vector<int> v)
{
    int answer = 0;
    while(start <= end)
    {
        int sum = 0;
        int mid = (start+end)/2;

        for(int i=0; i<N; ++i)
        {
            v[i] <= mid ? sum += v[i] : sum += mid;
        }

        if(sum <= K)
        {
            start = mid+1;
            answer = mid;
        }
        else
        {
            end = mid-1;
        }
    }
    return answer;
}

int main()
{
    std::cin >> N;
    std::vector<int> v(N);
    for(int i=0; i<N; ++i)
    {
        std::cin >> v[i];
    }
    std::cin >> K;

    std::cout << Binary_search(0,*max_element(v.begin(),v.end()),v);
}