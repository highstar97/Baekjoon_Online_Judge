#include <iostream>
#define MAX 21
using namespace std;

int N, Answer;
int Paths[MAX][MAX];
int InputArray[MAX][MAX];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> InputArray[i][j];
            Paths[i][j] = InputArray[i][j];
        }
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if ((i == k) || (j == k))
                    continue;

                // i -> k -> j라는 더 빠른 길이 있지만 입력 받은 표 값이 더 큰 경우 : 모순
                if (InputArray[i][j] > InputArray[i][k] + InputArray[k][j])
                {
                    cout << -1;
                    return 0;
                }

                // i -> k -> j라는 길을 사용하면 되는 경우
                if (InputArray[i][j] == InputArray[i][k] + InputArray[k][j])
                {
                    Paths[i][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            Answer += Paths[i][j];
        }
    }

    cout << Answer / 2;
}