#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
long long Answer;
int Parent[10001];
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
    cin >> V >> E;
    for (int i = 0; i <= V; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edges.emplace_back(make_pair(c, make_pair(a, b)));
    }

    sort(Edges.begin(), Edges.end());

    for (int i = 0; i < E; ++i)
    {
        int a = Edges[i].second.first;
        int b = Edges[i].second.second;

        if (Find(a) != Find(b))
        {
            Union(a, b);
            Answer += Edges[i].first;
        }
    }

    cout << Answer;
}