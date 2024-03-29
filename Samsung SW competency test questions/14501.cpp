#include <iostream>

#define max(a, b) a > b ? a : b
#define MAX 15
using namespace std;

int N, Answer;
int T[MAX + 1];
int P[MAX + 1];
int DP[MAX + 2]; // MAX일차 1일 일한 경우 MAX+1일이 퇴사날이지만 정산 받음

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + T[i]; j <= N + 1; ++j)
        {
            DP[j] = max(DP[j], DP[i] + P[i]);
        }
    }

    cout << DP[N + 1];
}