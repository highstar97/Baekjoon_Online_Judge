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

    do
    {
        for (int i = 0; i < M; ++i)
            cout << Vec[i] << " ";
        cout << '\n';
        reverse(Vec.begin() + M, Vec.end());
    } while (next_permutation(Vec.begin(), Vec.end()));
}

int main()
{
    cin >> N >> M;
    Solution(N, M);
}