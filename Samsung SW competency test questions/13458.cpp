#include <iostream>
#define MAX(a, b) a > b ? a : b

using namespace std;

int N, B, C;
long long Answer;
int Place[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Place[i];
    }

    cin >> B >> C;

    // 총감독은 한명씩 반드시 필요
    for (int i = 0; i < N; ++i)
    {
        Place[i] = max(0, Place[i] - B);
        ++Answer;
    }

    // 부감독은 여러명 가능
    for (int i = 0; i < N; ++i)
    {
        if (Place[i] == 0)
            continue;

        Answer += (Place[i] / C);
        if (Place[i] % C != 0)
        {
            ++Answer;
        }
    }

    cout << Answer;
}