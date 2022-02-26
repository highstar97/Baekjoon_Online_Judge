#include <iostream>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    int score[N];
    int answer[N];
    for(int i=0; i<N; ++i)
    {
        std::cin >> score[i]; 
    }

    answer[0] = score[0];
    answer[1] = score[0] + score[1];
    answer[2] = std::max(score[0]+score[2], score[1]+score[2]);
    for(int i=3; i<N; ++i)
    {
        answer[i] = std::max(answer[i-2]+score[i], answer[i-3]+score[i-1]+score[i]);
    }
    std::cout << answer[N-1];
}