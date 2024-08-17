#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> Previous(20001, -1);

void Dijkstra(int start, vector<vector<int>> &Graphs, vector<int> &Distances)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.emplace(0, start); // distance, node
    Distances[start] = 0;

    while (!PQ.empty())
    {
        int Distance = PQ.top().first;
        int CurrentNode = PQ.top().second;
        PQ.pop();

        if (Distances[CurrentNode] < Distance)
            continue;

        for (int i = 0; i < Graphs[CurrentNode].size(); ++i)
        {
            int NextNode = Graphs[CurrentNode][i];
            int Cost = Distance + 1;
            if (Distances[NextNode] > Cost)
            {
                Distances[NextNode] = Cost;
                Previous[NextNode] = CurrentNode;
                PQ.emplace(make_pair(Cost, NextNode));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int Answer = 0;
    int Start = 1;

    vector<int> Distances(n + 1, 1e9);

    // sort(edge.begin(), edge.end()); // 오름차순 정렬

    vector<vector<int>> Graphs(n + 1, vector<int>());
    for (int i = 0; i < edge.size(); ++i)
    {
        Graphs[edge[i][0]].emplace_back(edge[i][1]);
        Graphs[edge[i][1]].emplace_back(edge[i][0]);
    }

    // 다익스트라
    Dijkstra(Start, Graphs, Distances);

    int max = *max_element(Distances.begin() + 1, Distances.end());
    for (int Distance : Distances)
        if (Distance == max)
            ++Answer;

    // 재미로 하는 경로 추적
    for (int i = 1; i <= n; ++i)
    {
        if (i == Start)
            continue;

        if (Distances[i] == 1e9)
            continue;

        cout << "Paths " << Start << " to " << i << " : ";
        stack<int> path;
        for (int at = i; at != -1; at = Previous[at])
        {
            path.emplace(at);
        }

        while (!path.empty())
        {
            cout << path.top();
            path.pop();
            if (!path.empty())
                cout << " -> ";
        }
        cout << endl;
    }

    return Answer;
}

int main()
{
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}