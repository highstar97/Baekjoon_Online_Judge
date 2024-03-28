#include <iostream>
#define MAX 100001
using namespace std;

int G, P, Answer;
int Parent[MAX];

int Find(int a)
{

    if (Parent[a] == a)
    {
        return a;
    }
    return Parent[a] = Find(Parent[a]);
}

/*
4번 게이트에 비행기 도킹 시,
다음에 4번 게이트를 원하는 비행기는 4보다 작은 게이트 중 비어있는 3번 게이트에 도킹
만약 3번이 차있었다면, 2번으로 갔을 것
=> 즉, 게이트가 찼다면 가장 가까운(작은쪽으로) 게이트로 부모를 설정해두면 빠르게 접근 가능
*/
int main()
{
    cin >> G >> P;
    for (int i = 1; i <= G; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 1; i <= P; ++i)
    {
        int gate;
        cin >> gate;
        // gate보다 작은 게이트들이 꽉 참.
        if (Find(gate) == 0)
        {
            break;
        }
        else
        {
            ++Answer;
            // if gate = 4, Gate 4 is empty, Parent[4] = Find(4-1);
            Parent[Find(gate)] = Find(Find(gate) - 1);
        }
    }

    cout << Answer;
}