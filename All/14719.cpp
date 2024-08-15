/*
    BruteForce + 구현

    빠르게 아이디어를 찾고, 구현하는 능력이 필요...
    이 문제의 핵심 : max_element + (-> <- 방향 크로스 체크)
        최대 높이의 인덱스가 여러 개 있을 때, max_element는 가장 작은 iterator를 반환.
        즉, 같은 최대 높이 사이의 빗물도 계산됨.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W, Answer;

int main()
{
    cin >> H >> W;
    vector<int> Vec(W, 0);
    for (int i = 0; i < W; ++i)
    {
        cin >> Vec[i];
    }

    int Max_H_Index = max_element(Vec.begin(), Vec.end()) - Vec.begin();
    int LeftHegiht = Vec.front();
    int RightHegiht = Vec.back();

    // 왼쪽 방향
    for (int i = 0; i < Max_H_Index; ++i)
    {
        LeftHegiht < Vec[i] ? LeftHegiht = Vec[i] : Answer += LeftHegiht - Vec[i];
    }

    // 오른쪽 방향
    for (int i = W - 1; i > Max_H_Index; --i)
    {
        RightHegiht < Vec[i] ? RightHegiht = Vec[i] : Answer += RightHegiht - Vec[i];
    }
    
    cout << Answer;
    return 0;
}