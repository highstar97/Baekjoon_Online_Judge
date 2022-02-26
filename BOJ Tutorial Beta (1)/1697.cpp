#include <iostream>
#include <queue>

int N, K;
bool visited[100001] = {false};

int BFS()
{
    int count = 0;
    std::queue<int> q;
    q.emplace(N);
    visited[N] = true;

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; ++i)
        {   
            int current = q.front();
            if(current == K)
            {
                return count;
            }
            if(0 <= current-1 && !visited[current-1])
            {
                visited[current-1] = true;
                q.emplace(current-1);
            }
            if(current+1 < 100001 && !visited[current+1])
            {
                visited[current+1] = true;
                q.emplace(current+1);
            }
            if(current*2 < 100001 && !visited[current*2])
            {
                visited[current*2] = true;
                q.emplace(current*2);
            }
            q.pop();    
        }
        count++;
    }
    return count;
}

int main()
{
    std::cin >> N >> K;

    std::cout << BFS();
}