#include <iostream>
#include <vector>

int N, M;
int answer = 0;

void DFS(int start, std::vector<int> graph[], std::vector<bool> &visited)
{
    visited[start] = true;
    
    for(int i=0; i<graph[start].size(); ++i)
    {
        int next = graph[start][i];
        if(!visited[next])
        {
            visited[next] = true;
            answer++;
            DFS(next,graph,visited);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    std::vector<int> graph[N+1];
    std::vector<bool> visited(N+1);
    std::fill(visited.begin(),visited.end(),false);

    for(int i=0; i<M; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    DFS(1,graph,visited);
    std::cout << answer;
}