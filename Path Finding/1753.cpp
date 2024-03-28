#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int V, E, Start;
int Distances[20001];
vector<pair<int, int>> Graph[20001];

void Dijkstra(int StartNode)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(make_pair(0, StartNode));
    Distances[StartNode] = 0;

    while (!pq.empty())
    {
        int Distance = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (Distances[CurrentNode] < Distance)
        {
            continue;
        }

        for (int i = 0; i < Graph[CurrentNode].size(); ++i)
        {
            int Cost = Distance + Graph[CurrentNode][i].second;
            if (Cost < Distances[Graph[CurrentNode][i].first])
            {
                Distances[Graph[CurrentNode][i].first] = Cost;
                pq.emplace(make_pair(Cost, Graph[CurrentNode][i].first));
            }
        }
    }
}

int main()
{
    cin >> V >> E >> Start;
    int u, v, w;
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
        Graph[u].emplace_back(make_pair(v, w));
    }

    fill_n(Distances, 20001, INF);

    Dijkstra(Start);

    for (int i = 1; i <= V; ++i)
    {
        if (Distances[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << Distances[i] << "\n";
        }
    }
}