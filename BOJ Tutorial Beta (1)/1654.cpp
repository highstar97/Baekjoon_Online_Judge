#include <iostream>
#include <vector>
#include <algorithm>

int K, N;
std::vector<long long> len;

long long Binary_search(long long start, long long end)
{
    long long answer = 0;
    while(start <= end)
    {
        long long num = 0;
        long long mid = (start+end)/2;

        for(int i=0; i<K; ++i)
        {
            num += len[i]/mid;
        }

        if(num < N)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
            answer < mid ? answer = mid : answer;
        }
    }
    return answer;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> K >> N;
    for(int i=0; i<K; ++i)
    {
        long long input;
        std::cin >> input;
        len.emplace_back(input);
    }

    std::cout << Binary_search(1, *max_element(len.begin(),len.end()));
}