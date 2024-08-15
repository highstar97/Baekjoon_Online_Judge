/*
    BruteForce + 구현

    빠르게 아이디어를 찾고, 구현하는 능력이 필요...
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Answer;
struct Frame
{
    int x;
    int height;
    Frame(int L, int H) : x(L), height(H) {};
};
vector<Frame> Array;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int L, H;
        cin >> L >> H;
        Array.emplace_back(Frame(L, H));
    }

    sort(Array.begin(), Array.end(), [](Frame a, Frame b)
         { return a.x < b.x; });

    int left = 0;
    int right = Array.size() - 1;

    // 왼쪽에서 오른쪽으로
    for (int i = 0; i < Array.size(); ++i)
    {
        if (Array[left].height < Array[i].height)
        {
            Answer += (Array[i].x - Array[left].x) * Array[left].height;
            left = i;
        }
    }

    // 오른쪽에서 왼쪽으로
    for (int i = Array.size() - 1; i >= 0; --i)
    {
        if (Array[right].height < Array[i].height)
        {
            Answer += (Array[right].x - Array[i].x) * Array[right].height;
            right = i;
        }
    }

    // 마무리
    Answer += (Array[right].x - Array[left].x + 1) * Array[left].height;

    cout << Answer;
    return 0;
}