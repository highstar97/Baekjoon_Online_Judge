#include <iostream>
#include <vector>
#include <queue>
#define MAX 4001
#define INF 1e9
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
using namespace std;

int N, M, Answer;
int FoxDistances[MAX];
int WolfDistances[2][MAX];
vector<pii> Paths[MAX];

void Dijkstra_Fox(int StartNode)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(make_pair(0, StartNode));
    FoxDistances[StartNode] = 0;

    while (!pq.empty())
    {
        int Distance = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (FoxDistances[CurrentNode] < Distance)
        {
            continue;
        }

        for (int i = 0; i < Paths[CurrentNode].size(); ++i)
        {
            int NextNode = Paths[CurrentNode][i].first;
            int Cost = Distance + Paths[CurrentNode][i].second;
            if (Cost < FoxDistances[NextNode])
            {
                FoxDistances[NextNode] = Cost;
                pq.emplace(make_pair(Cost, NextNode));
            }
        }
    }
}

void Dijkstra_Wolf(int StartNode)
{
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.emplace(make_pair(0, make_pair(StartNode, 0)));
    // WolfDistances[0][StartNode] = 0;

    while (!pq.empty())
    {
        int Distance = pq.top().first;
        int CurrentNode = pq.top().second.first;
        int CurrentState = pq.top().second.second; // CanAccel : 0, CantAccel : 1
        pq.pop();

        if (WolfDistances[CurrentState][CurrentNode] < Distance)
        {
            continue;
        }

        for (int i = 0; i < Paths[CurrentNode].size(); ++i)
        {
            int Cost;
            int NextNode = Paths[CurrentNode][i].first;

            if (CurrentState == 0)
            {
                Cost = Distance + (Paths[CurrentNode][i].second) / 2;
            }
            else
            {
                Cost = Distance + (Paths[CurrentNode][i].second) * 2;
            }

            if (Cost < WolfDistances[CurrentState][NextNode])
            {
                WolfDistances[CurrentState][NextNode] = Cost;
                pq.emplace(make_pair(Cost, make_pair(NextNode, (CurrentState + 1) / 2)));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Paths[a].emplace_back(make_pair(b, w * 2));
        Paths[b].emplace_back(make_pair(a, w * 2));
    }

    fill_n(FoxDistances, MAX, INF);
    fill_n(WolfDistances[0], MAX, INF);
    fill_n(WolfDistances[1], MAX, INF);

    Dijkstra_Fox(1);
    Dijkstra_Wolf(1);

    for (int i = 0; i <= N; ++i)
    {
        if (FoxDistances[i] < min(WolfDistances[0][i], WolfDistances[1][i]))
        {
            ++Answer;
        }
    }

    cout << Answer;
}