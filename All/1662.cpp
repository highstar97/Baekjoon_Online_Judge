/*
    K(Q) : Q가 K번 반복 (K는 한자리 정수)
    ex)
    1(9)            = 9
    71(9)           = 79
    562(71(9))      = 567979
    33(562(71(9)))  = 3567979567979567979 => Answer = 19
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int Answer;
string S;

void Solution(string S)
{
    stack<int> Stack;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == '(')
        {
            Stack.emplace(-1);
        }
        if (isdigit(S[i]))
        {
            if (i + 1 < S.size() && S[i + 1] == '(')
            {
                Stack.emplace(S[i] - '0');
            }
            else
            {
                Stack.emplace(1);
            }
        }
        if (S[i] == ')')
        {
            int length = 0;
            while (Stack.top() != -1)
            {
                length += Stack.top();
                Stack.pop();
            }
            Stack.pop();           // -1 제거
            length *= Stack.top(); //  '(' 앞의 숫자 K와 곱
            Stack.pop();           // K 제거
            Stack.emplace(length);
        }
    }

    while (!Stack.empty())
    {
        Answer += Stack.top();
        Stack.pop();
    }
}

int main()
{
    cin >> S;
    Solution(S);
    cout << Answer;
}