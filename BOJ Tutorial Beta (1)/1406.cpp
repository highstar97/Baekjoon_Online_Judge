#include <iostream>
#include <string>
#include <stack>

int M;
std::string input;

std::stack<char> l;
std::stack<char> r;

void Function(std::string str)
{
    switch(str[0])
    {
        case 'L':
        {
            if(!l.empty())
            {
                r.emplace(l.top());
                l.pop();
            }
            break;
        }
        case 'D':
        {
            if(!r.empty())
            {
                l.emplace(r.top());
                r.pop();
            }
            break;
        }
        case 'B':
        {
            if(!l.empty())
            {
                l.pop();
            }
            break;
        }
        case 'P':
        {
            l.emplace(str[2]);
            break;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> input;
    std::cin >> M;
    std::cin.ignore();
    
    for(int i=0; i<input.length(); i++)
    {
        l.emplace(input[i]);
    }

    while(M--)
    {
        std::getline(std::cin, input);
        Function(input);
    }

    while(!l.empty())
    {
        r.push(l.top());
        l.pop();
    }

    while(!r.empty())
    {
        std::cout << r.top();
        r.pop();
    }

    return 0;
}