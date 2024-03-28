#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M;
int Distances[MAX];
int DistancesBeRemoved[MAX];
int Route[MAX];
vector<pair<int, int>> Paths[MAX];

int Dijkstra()
{
    fill_n(Distances, MAX, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(make_pair(0, 1));
    Distances[1] = 0;
    Route[1] = 1;

    while (!pq.empty())
    {
        int Distance = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (Distances[CurrentNode] < Distance)
        {
            continue;
        }

        for (int i = 0; i < Paths[CurrentNode].size(); ++i)
        {
            int NextNode = Paths[CurrentNode][i].first;
            int Cost = Distance + Paths[CurrentNode][i].second;
            if (Cost < Distances[NextNode])
            {
                Distances[NextNode] = Cost;
                Route[NextNode] = CurrentNode; // NextNode로 가는 경로는 CurrentNode로부터 시작
                pq.emplace(make_pair(Cost, NextNode));
            }
        }
    }

    return Distances[N];
}

int Dijkstra(int StartNodeBeRemoved, int EndNodeBeRemoved)
{
    fill_n(DistancesBeRemoved, MAX, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(make_pair(0, 1));
    DistancesBeRemoved[1] = 0;

    while (!pq.empty())
    {
        int Distance = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (DistancesBeRemoved[CurrentNode] < Distance)
        {
            continue;
        }

        for (int i = 0; i < Paths[CurrentNode].size(); ++i)
        {
            int NextNode = Paths[CurrentNode][i].first;

            if (CurrentNode == StartNodeBeRemoved && NextNode == EndNodeBeRemoved || CurrentNode == EndNodeBeRemoved && NextNode == StartNodeBeRemoved)
            {
                continue;
            }

            int Cost = Distance + Paths[CurrentNode][i].second;
            if (Cost < DistancesBeRemoved[NextNode])
            {
                DistancesBeRemoved[NextNode] = Cost;
                pq.emplace(make_pair(Cost, NextNode));
            }
        }
    }

    return DistancesBeRemoved[N];
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Paths[a].emplace_back(make_pair(b, w));
        Paths[b].emplace_back(make_pair(a, w));
    }

    int BasicAnswer = Dijkstra();
    int RemovedAnswer = 0;
    int Destination = N;
    while (Route[Destination] != 1)
    {
        RemovedAnswer = max(RemovedAnswer, Dijkstra(Route[Destination], Destination));  // Route[목적지] (목적지로 가기 위한 직전 노드) -> 목적지
        Destination = Route[Destination];
    }

    RemovedAnswer == INF ? cout << "-1" : cout << RemovedAnswer - BasicAnswer;
}