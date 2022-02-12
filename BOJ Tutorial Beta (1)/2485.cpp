#include <iostream>

int N;

int GCD(int A, int B)
{
    if(A < B)
    {
        int temp = A;
        int A = B;
        int B = temp;
    }

    if(B == 0)
    {
        return A;
    }
    else
    {
        return GCD(B, A%B);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N;
    int tree[N];
    for(int i=0; i<N; ++i)
    {
        std::cin >> tree[i];
    }

    int between[N-1];
    for(int i=1; i<N; ++i)
    {
        between[i-1] = tree[i]-tree[i-1];
    }

    int min;
    for(int i=1; i<N-1; ++i)
    {
        if(min == 1)
        {
            std::cout << tree[N-1] - tree[0] + 1 - N;
            exit(0);
        }
        int A = between[i-1];
        int B = between[i];
        min = GCD(A,B);
        between[i] = min;
    }
    int exp = tree[N-1] - tree[0] + 1;
    if(exp%min != 0)
    {
        std::cout << exp/min + 1 - N;
    }
    else
    {
        std::cout << exp/min - N;
    }
    return 0;
}