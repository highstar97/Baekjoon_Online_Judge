/*
    조합 문제.

    Bitmask(11...100...0) + prev_permutaion를 기억하자.
    Bitmask(00...011...1) + next_permutaion도 가능
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Solution(int N, int M)
{
    vector<int> Vec(N, 0);
    for (int i = 0; i < N; ++i)
    {
        Vec[i] = i + 1;
    }

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
    Solution(N, M);
}