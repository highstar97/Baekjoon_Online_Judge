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
