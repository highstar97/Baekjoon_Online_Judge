#include <iostream>
#include <vector>
#include <algorithm>

int N;

void Permutation(std::vector<int> v, int r)
{
    sort(v.begin(),v.end());
    do
    {
        for(int i=0; i<r; i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << '\n';
        reverse(v.begin()+r, v.end());
    }while(next_permutation(v.begin(), v.end()));
}

int main()
{
    std::cin >> N;
    std::vector<int> v(N);

    for(int i=0; i<N; ++i)
    {
        v[i] = i+1;    
    }
    Permutation(v, N);
}