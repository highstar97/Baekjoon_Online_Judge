#include <iostream>
#define MAX 401
using namespace std;

int N, K, S;
int Paths[MAX][MAX];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;
        Paths[a][b] = 1; // a -> b : 1
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (i == k || j == k)
                    continue;

                if (Paths[i][k] == 0 || Paths[k][j] == 0)
                    continue;

                Paths[i][j] = max(Paths[i][j], Paths[i][k] + Paths[k][j]);
            }
        }
    }

    cin >> S;
    for (int i = 0; i < S; ++i)
    {
        int a, b;
        cin >> a >> b;
        Paths[a][b] > 0 ? cout << "-1\n" : Paths[b][a] > 0 ? cout << "1\n"
                                                           : cout << "0\n";
    }
}