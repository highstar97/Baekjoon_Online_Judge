#include <iostream>
#define MAX 1500001
using namespace std;

int N, Answer;
int MaxPay[MAX];
pair<int, int> Data[MAX];

void Solve()
{
    int CurrentMax = 0;
    for (int i = 1; i <= N + 1; ++i)
    {
        CurrentMax = max(CurrentMax, MaxPay[i]);
        if (i + Data[i].first > N + 1)
        {
            continue;
        }
        MaxPay[i + Data[i].first] = max(MaxPay[i + Data[i].first], CurrentMax + Data[i].second);
    }
    Answer = CurrentMax;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int time, pay;
        cin >> time >> pay;
        Data[i] = {time, pay};
    }

    Solve();

    cout << Answer;
}