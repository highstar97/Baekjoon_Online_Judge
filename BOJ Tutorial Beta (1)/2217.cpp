#include <iostream>
#include <algorithm>

int N;

int main()
{
    std::cin >> N;
    int rope[N];
    for(int i=0; i<N; ++i)
    {
        std::cin >> rope[i];
    }

    std::sort(rope,rope+N,std::greater<int>());

    int answer = 0;
    for(int i=0; i<N; ++i)
    {
        int sum = rope[i] * (i+1);
        if(sum > answer)
            answer = sum;
    }
    std::cout << answer;
}