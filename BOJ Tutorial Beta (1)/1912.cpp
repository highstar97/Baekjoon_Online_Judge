#include <iostream>

int N;
int num[100000];

int Function()
{
    int sum = 0;
    int max = -1001;
    for(int i=0; i<N; ++i)
    {
        sum += num[i];
        // max 판별
        if(max < sum)
        {
            max = sum;
        }
        // 연속합이 최대가 될 수 없는 경우 새로 시작
        if(sum < 0)
        {
            sum = 0;
        }
        
    }
    return max;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        std::cin >> num[i];
    }

    std::cout << Function();
}