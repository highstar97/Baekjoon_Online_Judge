#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9

using namespace std;

int N, M, X, Answer;
int Distances[MAX][MAX];
vector<pair<int, int>> Graph[MAX];

void Dijkstra(int StartNode)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, StartNode);
    Distances[StartNode][StartNode] = 0;

    while (!pq.empty())
    {
        int Distance = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (Distances[StartNode][CurrentNode] < Distance)
        {
            continue;
        }

        for (int i = 0; i < Graph[CurrentNode].size(); ++i)
        {
            int NextNode = Graph[CurrentNode][i].first;
            int Cost = Distance + Graph[CurrentNode][i].second;
            if (Cost < Distances[StartNode][NextNode])
            {
                Distances[StartNode][NextNode] = Cost;
                pq.emplace(Cost, NextNode);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;
    for (int i = 1; i <= M; ++i)
    {
        int A, B, T;
        cin >> A >> B >> T;
        Graph[A].emplace_back(make_pair(B, T));
    }

    for (int i = 1; i <= N; ++i)
    {
        fill_n(Distances[i], N+1, INF);
    }

    for (int i = 1; i <= N; ++i)
    {
        Dijkstra(i);
    }

    for (int i = 1; i <= N; ++i)
    {
        Answer = max(Answer, Distances[i][X] + Distances[X][i]);
    }

    cout << Answer;
}