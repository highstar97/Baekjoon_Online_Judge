#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1002

using namespace std;

int N, M, K, Answer;
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
    cin >> N >> M >> K;
    for (int i = 0; i <= N; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < K; ++i)
    {
        int input;
        cin >> input;
        Parent[input] = 0; // 발전소가 있는 도시는 0번 도시로 간주
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edges.emplace_back(make_pair(w, make_pair(u, v)));
    }

    sort(Edges.begin(), Edges.end());

    for (int i = 0; i < M; ++i)
    {
        int u = Edges[i].second.first;
        int v = Edges[i].second.second;
        if (Find(u) != Find(v))
        {
            Union(u, v);
            Answer += Edges[i].first;
        }
    }

    cout << Answer;
}