#include <iostream>
#include <stack>

int T;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    std::cin.ignore();
    while(T--)
    {
        int isbalance = 0;
        std::stack<char> s;
        std::string input;
        std::getline(std::cin,input);
        for(int i=0; i<input.length(); ++i)
        {
            s.emplace(input[i]);
        }

        while(!s.empty())
        {
            if(isbalance == 0 && s.top() == '(')
            {
                std::cout << "NO" << '\n';
                break;
            }
            if(s.top() == '(')
            {
                isbalance--;
            }
            else
            {
                isbalance++;
            }
            s.pop();
        }

        if(s.empty() && isbalance == 0)
        {
            std::cout << "YES" << '\n';
        }
        else if(s.empty() && isbalance != 0)
        {
            std::cout << "NO" << "\n";
        }
    }
    return 0;
}