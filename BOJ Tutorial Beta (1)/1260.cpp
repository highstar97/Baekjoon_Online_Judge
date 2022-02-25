#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, start;

void DFS(std::vector<int> graph[], std::vector<bool> &visited, int start)
{
    int current = start;
    visited[current] = true;
    std::cout << current << " ";

    for(int i=0; i<graph[current].size(); ++i)
    {
        int next = graph[current][i];
        if(visited[next] == false)
        {
            DFS(graph,visited,next);
        }
    }
}

void BFS(std::vector<int> graph[], std::vector<bool> &visited, int start)
{
    std::queue<int> q;
    q.emplace(start);
    visited[start] = true;
    std::cout << start << " ";

    while(!q.empty())
    {
        for(int i=0; i<graph[q.front()].size(); ++i)
        {
            int next = graph[q.front()][i];
            if(visited[next] == false)
            {
                q.emplace(next);
                visited[next] = true;
                std::cout << next << " ";
            }
        }
        q.pop();
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N >> M >> start;
    std::vector<int> graph[N+1];
    std::vector<bool> visited(N+1,false);
    for(int i=0; i< M; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    for(int i=1; i<=N; ++i)
    {
        std::sort(graph[i].begin(),graph[i].end());
    }
    DFS(graph,visited,start);
    std::cout << "\n";
    std::fill(visited.begin(),visited.end(),false);
    BFS(graph,visited,start);
}