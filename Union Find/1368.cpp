#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 302

using namespace std;

int N, Answer;
int Parent[MAX];
vector<pair<int, pair<int, int>>> Edges;

/*
    우물을 파는 경우를 가상의 노드 0으로 생성하고 풀면 MST로 풀림
    ex) 논이 1 ~ 300번까지 있으면 우물을 파는 경우를 0으로 생각하고 0 ~ 300까지 모두 연결하는 최소 트리 생각
*/

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
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        Parent[i] = i;
        int cost;
        cin >> cost;
        Edges.emplace_back(make_pair(cost, make_pair(0, i)));
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int cost;
            cin >> cost;
            if (i != j)
            {
                Edges.emplace_back(make_pair(cost, make_pair(i, j)));
            }
        }
    }

    sort(Edges.begin(), Edges.end());

    for (int i = 0; i < N * N; ++i)
    {
        int Pi = Edges[i].second.first;
        int Pj = Edges[i].second.second;
        if (Find(Pi) != Find(Pj))
        {
            Union(Pi, Pj);
            Answer += Edges[i].first;
        }
    }

    cout << Answer;
}