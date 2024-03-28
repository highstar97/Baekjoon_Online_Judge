#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int N, M;
int Graph[201][201];
int Answer[201][201];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            i == j ? Graph[i][j] = 0 : Graph[i][j] = INF;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u][v] = w;
        Graph[v][u] = w;
        Answer[u][v] = v;
        Answer[v][u] = u;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (Graph[i][j] > Graph[i][k] + Graph[k][j])
                {
                    Graph[i][j] = Graph[i][k] + Graph[k][j];
                    Answer[i][j] = Answer[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (Answer[i][j] == 0)
                cout << "- ";
            else
                cout << Answer[i][j] << ' ';
        }
        cout << '\n';
    }
}