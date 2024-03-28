#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
long long arr[11][2001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // arr 채우기
    // arr[i][j] : j를 포함해서 1~j중 i개를 고를 수 있는 경우의 수
    for (int i = 1; i < 11; ++i)
    {
        for (int j = 1; j < 2001; ++j)
        {
            if (i == 1)
            {
                arr[i][j] = 1;
                continue;
            }
            // ex
            // arr[2][4] = arr[1][1] + arr[1][2] = 1 + 1 = {1,4}, {2,4}
            for (int k = 1; k <= j / 2; ++k)
            {
                arr[i][j] += arr[i - 1][k];
            }
        }
    }

    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        long long answer = 0;
        for (int i = 1; i <= M; ++i)
        {
            answer += arr[N][i];
        }
        cout << answer << '\n';
    }
}