#include <iostream>
#include <queue>

int N,M;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    while(N--)
    {
        int n;
        int answer = 0;
        std::queue<std::pair<int,int>> q;
        std::priority_queue<int> pq;
        
        std::cin >> n >> M;
        for(int i=0; i<n; ++i)
        {
            int important;
            std::cin >> important;
            q.emplace(std::make_pair(important,i));
            pq.emplace(important);
        }

        while(!q.empty())
        {
            if(q.front().first == pq.top())
            {
                if(q.front().second == M)
                {
                    std::cout << answer+1 << '\n';
                    break;
                }
                else
                {
                    q.pop();
                    pq.pop();
                    ++answer;
                }
            }
            else
            {
                q.emplace(q.front());
                q.pop();
            }
        }
    }
    return 0;
}