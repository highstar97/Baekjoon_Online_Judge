#include <iostream>
#include <queue>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> N;
    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for(int i=0; i<N; ++i)
    {
        int input;
        std::cin >> input;
        if(max_heap.size() > min_heap.size())
        {
            min_heap.emplace(input);
        }
        else
        {
            max_heap.emplace(input);
        }

        if( (max_heap.size() > 0 && min_heap.size() > 0) && max_heap.top() > min_heap.top())
        {
            int a = max_heap.top();
            int b = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.emplace(b);
            min_heap.emplace(a);
        }
        std::cout << max_heap.top() << '\n';
    }    
}