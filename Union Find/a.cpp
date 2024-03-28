#include <iostream>
#include <vector>
using namespace std;

int Max = -99999999;

void Add(int sum, int index, bool bPassed, vector<int> scores)
{
    if (index == scores.size())
    {
        Max = max(Max, sum);
        return;
    }

    // 그 전에 버렸다면
    if (bPassed)
    {
        // 추가하기
        Add(sum + scores[index], index + 1, false, scores);
    }
    else
    {
        // 버리기
        Add(sum, index + 1, true, scores);
        // 추가하기
        Add(sum + scores[index], index + 1, false, scores);
    }
}

int GetMaxScore(vector<int> scores)
{
    Add(0, 0, false, scores);
    return Max;
}

int main()
{
    cout << GetMaxScore({9, -1, -3, 4, 5});
}