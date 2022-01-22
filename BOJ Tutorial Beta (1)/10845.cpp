#include <iostream>
#include <string>
#include <queue>

int N;
std::string arr[10000];
std::queue<int> q;

void Function(std::string str)
{
    if(str[0] == 'p')
    {
        if(str[1] == 'u')
        {
            q.emplace(stoi(str.substr(5)));
        }
        else if(str[1] == 'o')
        {
            if(q.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << q.front() << '\n';
                q.pop();
            }
        }
    }
    else if(str[0] == 's')
    {
        std::cout << q.size() << '\n';
    }
    else if(str[0] == 'e')
    {
        if(q.empty())
        {
            std::cout << 1 << '\n';
        }
        else
        {
            std::cout << 0 << '\n';
        }
    }
    else if(str[0] == 'f')
    {
        if(q.empty())
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << q.front() << '\n';
        }
    }
    else if(str[0] == 'b')
    {
        if(q.empty())
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << q.back() << '\n';
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