/*
    순열 문제.

    next_permutaion + reverse를 기억하자.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Vec;

void Solution(vector<int>& Vec, int M)
{
    sort(Vec.begin(), Vec.end());
    
    do
    {
        for(int i=0; i<M; ++i)
            cout << Vec[i] << " ";
        cout << '\n';
        reverse(Vec.begin()+M, Vec.end());
    }while(next_permutation(Vec.begin(),Vec.end()));
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        int input;
        cin >> input;
        Vec.emplace_back(input);
    }
    Solution(Vec, M);
}