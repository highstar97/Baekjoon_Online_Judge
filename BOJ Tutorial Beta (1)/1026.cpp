#include <iostream>
#include <algorithm>
#include <vector>

int N;
int answer = 0;

int main() 
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i=0; i<N; ++i)
    {
        std::cin >> A[i];
    }

    for(int i=0; i<N; ++i)
    {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());
    std::sort(B.begin(), B.end(), std::less<int>());

    for(int i=0; i<N; ++i)
    {
        answer += A[i]*B[i];
    }
    std::cout << answer;
    return 0;
}