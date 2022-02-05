#include <iostream>

int N;
int Min = 1000000001;
int Max = -1000000001;
int num[11];
int operators[4];

void Function(int result, int depth)
{
    if(depth == N)
    {
        result < Min ? Min = result : Min; // false일 경우 의미 없음
        result > Max ? Max = result : Max; // false일 경우 의미 없음
        return;
    }
    for(int i=0; i<4; ++i)
    {
        if(operators[i] > 0)
        {
            operators[i]--;
            if(i==0)
            {
                Function(result + num[depth], depth+1);
            }
            else if(i==1)
            {
                Function(result - num[depth], depth+1);
            }
            else if(i==2)
            {
                Function(result * num[depth], depth+1);
            }
            else
            {
                Function(result / num[depth], depth+1);
            }
            operators[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        }
    }
    return;
}

int main()
{
    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        std::cin >> num[i];
    }
    for(int i=0; i<4; ++i)
    {
        std::cin >> operators[i];
    }
    Function(num[0],1);
    std::cout << Max << '\n' << Min;
}