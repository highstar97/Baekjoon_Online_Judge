#include <iostream>
#include <algorithm>

int N, M;

void Combination(int arr[], int r)
{
    std::string str;
    for(int i=0; i<N; ++i)
    {
        i<r ? str += "1" : str += "0";
    }
    do
    {
        for(int i=0; i<N; ++i)
        {
            if(str[i] == '1')
            {
                std::cout << arr[i] << " ";
            }
        }
        std::cout << '\n';
    }while(prev_permutation(str.begin(),str.end()));
}

int main()
{
    std::cin >> N >> M;
    int arr[N];
    for(int i=0; i<N; ++i)
    {
        arr[i] = i+1;
    }
    Combination(arr, M);
    return 0;
}