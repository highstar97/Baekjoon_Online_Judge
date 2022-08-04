#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using ii = std::pair<int,int>;

int N, K;

struct Compare
{
    bool operator()(ii&a, ii&b)
    {
        if(a.first == b.first)
        {
            return a.second > b.second;
        }
        else
        {
            return a.first > b.first;
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    long long answer = 0;
    std::cin >> N >> K;
    std::priority_queue<ii, std::vector<ii>, Compare> jewel;    // 내림차순
    for(int i=0; i<N; ++i)
    {
        int weight, price;
        std::cin >> weight >> price;
        jewel.emplace(std::make_pair(weight,price));
    }

   std::vector<int> bag;
    for(int i=0; i<K; ++i)
    {
        int weight;
        std::cin >> weight;
        bag.emplace_back(weight);
    }

    sort(bag.begin(),bag.end());    // 내림차순 정렬
    
    std::cout << answer;
}