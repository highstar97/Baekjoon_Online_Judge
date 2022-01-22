#include <iostream>
#include <string>
#include <stack>

int N;
std::string arr[10000];
std::stack<int> s;

void Function(std::string str)
{
    if(str[0] == 'p')
    {
        if(str[1] == 'u')
        {
            s.emplace(stoi(str.substr(5)));
        }
        else if(str[1] == 'o')
        {
            if(s.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << s.top() << '\n';
                s.pop();
            }
        }
    }
    else if(str[0] == 's')
    {
        std::cout << s.size() << '\n';
    }
    else if(str[0] == 'e')
    {
        if(s.empty())
        {
            std::cout << 1 << '\n';
        }
        else
        {
            std::cout << 0 << '\n';
        }
    }
    else if(str[0] == 't')
    {
        if(s.empty())
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << s.top() << '\n';
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    std::cin.ignore();

    for(int i=0; i<N; i++)
    {
        std::getline(std::cin,arr[i]);   
    }

    for(int i=0; i<N; i++)
    {
        Function(arr[i]);
    }

    return 0;
}