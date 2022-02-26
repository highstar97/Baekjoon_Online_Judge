#include <iostream>
#define MAX 1000001
#define INF 1e9

int N;
int data[MAX];

int main()
{
    std::cin >> N;
    std::fill_n(data,MAX,INF);

    data[0] = 0;
    data[1] = 0;
    for(int i=1; i<=N; ++i)
    {
        if(i+1 < MAX)
            data[i+1] = std::min(data[i]+1,data[i+1]);
        if(i*2 < MAX)
            data[i*2] = std::min(data[i]+1,data[i*2]);
        if(i*3 < MAX)
            data[i*3] = std::min(data[i]+1,data[i*3]);
    }
    std::cout << data[N];
}