#include <iostream>
#include <queue>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> N;

    std::priority_queue<int,std::vector<int>, std::greater<int>> pq;

    for(int i=0; i<N; ++i)
    {
        int input;
        std::cin >> input;
        if(input == 0)
        {
            if(pq.empty())
            {
                std::cout << "0\n";
            }
            else
            {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.emplace(input);
        }
    }
}