// bitset을 활용한 나의 풀이
/*
#include <iostream>
#include <math.h>
#include <bitset>

int N, S;
int answer = 0;
int arr[20];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N >> S;
    
    for(int i=0; i<N; ++i)
    {
        std::cin >> arr[i];
    }
    
    for(int i=1; i<pow(2,N); ++i)
    {
        std::bitset<20> bit = i;
        int sum = 0;
        for(int j=N-1; j>=0; --j)
        {
            sum += bit[j] * arr[N-1-j];
        }
        if(sum == S)
        {
            answer++;
        }
    }
    std::cout << answer;
    return 0;
}*/
// 백트레킹을 이용한 풀이
#include <iostream>

int arr[20];

int N, S, count = 0;

void DFS(int i, int tmp){
    if(i == N) return;
    if(tmp + arr[i] == S) count++;

    DFS(i+1,tmp);
    DFS(i+1,tmp+arr[i]);
}

int main() {
    std::cin >> N >> S;
    int tmp;
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    DFS(0,0);
    std::cout << count;
}