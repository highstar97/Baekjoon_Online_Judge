#include <iostream>
#include <queue>

int main()
{
    int N, answer = 0;
    std::cin >> N;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    while(N--)
    {
        int input;
        std::cin >> input;
        pq.emplace(input);
    }
    while(pq.size() != 1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        
        int C = A + B;
        answer += C;
        pq.emplace(C);
    }
    std::cout << answer;
}