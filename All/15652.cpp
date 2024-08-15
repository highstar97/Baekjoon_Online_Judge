/*
    비내림차순 중복 순열 문제 : 숫자 중복 사용 가능한 순열. 단 비내림차순
        비내림차순 : 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족

    중복 순열은 BackTracking!!! + 비내림차순 조건 추가
*/
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void GeneratePermutations(vector<int> &Vec, int Depth)
{
    if (Depth == M)
    {
        for (int data : Vec)
        {
            cout << data << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (!Vec.empty() && Vec.back() > i)
            continue;
        Vec.push_back(i);
        GeneratePermutations(Vec, Depth + 1);
        Vec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<int> Vec;
    GeneratePermutations(Vec, 0);

    return 0;
}
