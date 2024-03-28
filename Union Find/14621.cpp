#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, M, Answer;
char Sex[MAX];
int Parent[MAX];
vector<pair<int, pair<int, int>>> Edges;

int Find(int a)
{
    if (Parent[a] == a)
    {
        return a;
    }
    return Parent[a] = Find(Parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    a > b ? Parent[a] = b : Parent[b] = a;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        Parent[i] = i;
        cin >> Sex[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        Edges.emplace_back(make_pair(d, make_pair(u, v)));
    }

    sort(Edges.begin(), Edges.end());

    for (int i = 0; i < M; ++i)
    {
        int u = Edges[i].second.first;
        int v = Edges[i].second.second;
        if (Find(u) != Find(v) && Sex[u] != Sex[v])
        {
            Union(u, v);
            Answer += Edges[i].first;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        if (Find(Parent[i]) != 1)
        {
            cout << -1;
            return 0;
        }
    }
    cout << Answer;
}