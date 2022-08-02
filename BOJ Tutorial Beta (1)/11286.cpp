#include <iostream>
#include <queue>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    std::priority_queue<int, std::vector<int>, std::greater<int>> plus;
    std::priority_queue<int, std::vector<int>, std::less<int>> minus;
    while(N--)
    {
        int input;
        std::cin >> input;
        
        if(input == 0)
        {
            if(!plus.empty() && !minus.empty())
            {
                if(plus.top() < -1*minus.top())
                {
                    std::cout << plus.top() << '\n';
                    plus.pop();
                }
                else
                {
                    std::cout << minus.top() << '\n';
                    minus.pop();
                }
            }
            else if(!plus.empty() && minus.empty())
            {
                std::cout << plus.top() << '\n';
                plus.pop();
            }
            else if(plus.empty() && !minus.empty())
            {
                std::cout << minus.top() << '\n';
                minus.pop();
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        else
        {
            input > 0 ? plus.emplace(input) : minus.emplace(input);
        }
    }
}