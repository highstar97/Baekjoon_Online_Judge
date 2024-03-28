#include <iostream>

using namespace std;

int N, M, S, E;
int arr[2001];
bool IsPalindrome[2001][2001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    // 한글자
    for (int i = 1; i <= N; ++i)
    {
        IsPalindrome[i][i] = true;
    }

    // 두글자
    for (int i = 1; i <= N - 1; ++i)
    {
        if (arr[i] == arr[i + 1])
        {
            IsPalindrome[i][i + 1] = true;
        }
    }

    // 세글자 이상
    for (int i = 2; i <= N - 1; ++i)
    {
        for (int j = 1; i + j <= N; ++j)
        {
            if (arr[j] == arr[i + j] && IsPalindrome[j + 1][i + j - 1] == true)
            {
                IsPalindrome[j][i + j] = true;
            }
        }
    }

    cin >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> S >> E;
        IsPalindrome[S][E] == true ? cout << "1\n" : cout << "0\n";
    }
}