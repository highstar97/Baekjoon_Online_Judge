/*
    조합 문제.

    Bitmaks + prev|next_permutaion를 기억하자.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Vec;

void Solution(vector<int> &Vec)
{
    sort(Vec.begin(), Vec.end());

    string Bitmask = "";
    for (int i = 0; i < M; ++i)
    {
        Bitmask += "1";
    }
    for (int i = M; i < N; ++i)
    {
        Bitmask += "0";
    }

    do
    {
        for (int i = 0; i < N; ++i)
            if (Bitmask[i] == '1')
                cout << Vec[i] << " ";
        cout << '\n';
    } while (prev_permutation(Bitmask.begin(), Bitmask.end()));
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        Vec.emplace_back(input);
    }
    Solution(Vec);
}