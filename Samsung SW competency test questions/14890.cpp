#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, L, Answer;
int Map[100][100];

// 1 1 2 2 2 3 2 2 1 1 : O
// 1 1 2 2 2 3 2 2 1   : X
// 2개 씩 비교, Map[i][j] & Map[i][j+1]
// 같으면 패스, 다르면 작은쪽으로 L만큼 확인 경사로 이미 있는지 체크, 높이가 같은지 체크
void Check(vector<int> Line)
{
    vector<bool> IsUsed(Line.size(), false);
    for (int j = 0; j < N - 1; ++j)
    {
        if (abs(Line[j] - Line[j + 1]) > 1)
        {
            return;
        }
        if (Line[j] == Line[j + 1])
        {
            continue;
        }
        else if (Line[j] < Line[j + 1]) // _ _ 1 2 _ _
        {
            // j 포함 왼쪽 칸 크기 < 경사로 크기 : 경사로 놓을 수 없음
            if (j + 1 < L)
            {
                return;
            }

            // j 포함 왼쪽 칸 들에 경사로가 이미 놓여져 있지 않은지 체크
            set<int> Set;
            for (int k = j; k >= j - L + 1; --k)
            {
                Set.emplace(Line[k]);
                if (IsUsed[k])
                {
                    return;
                }
            }
            // 높이가 같은지 체크
            if (Set.size() != 1)
            {
                return;
            }
            // 경사로 추가
            for (int k = j; k >= j - L + 1; --k)
            {
                IsUsed[k] = true;
            }
        }
        else // _ _ 2 1 _ _
        {
            // j + 1 포함 오른쪽 칸 크기 < 경사로 크기 : 경사로 놓을 수 없음
            if (N - j < L)
            {
                return;
            }

            // j + 1 포함 오른쪽 칸 들에 경사로가 이미 놓여져 있지 않은지 체크
            set<int> Set;
            for (int k = j + 1; k <= j + L; ++k)
            {
                Set.emplace(Line[k]);
                if (IsUsed[k])
                {
                    return;
                }
            }
            // 높이가 같은지 체크
            if (Set.size() != 1)
            {
                return;
            }
            // 경사로 추가
            for (int k = j + 1; k <= j + L; ++k)
            {
                IsUsed[k] = true;
            }
        }
    }
    ++Answer;
}

int main()
{
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Map[i][j];
        }
    }

    vector<int> Line;
    // 가로 방향
    for (int row = 0; row < N; ++row)
    {
        Line.clear();
        for (int col = 0; col < N; ++col)
        {
            Line.emplace_back(Map[row][col]);
        }
        Check(Line);
    }
    // 세로 방향
    for (int col = 0; col < N; ++col)
    {
        Line.clear();
        for (int row = 0; row < N; ++row)
        {
            Line.emplace_back(Map[row][col]);
        }
        Check(Line);
    }

    cout << Answer << endl;
}