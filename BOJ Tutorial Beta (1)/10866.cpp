#include <iostream>
#include <string>
#include <deque>

int N;
std::string arr[10000];
std::deque<int> d;

void Function(std::string str)
{
    if(str[0] == 'p')
    {
        if(str[1] == 'u')
        {
            if(str[5] == 'f')
            {
                d.push_front(stoi(str.substr(11)));
            }
            else
            {
                d.push_back(stoi(str.substr(10)));
            }
        }
        else
        {
            if(str[4] == 'f')
            {
                if(d.empty())
                {
                    std::cout << -1 << '\n';
                }
                else
                {
                    std::cout << d.front() << '\n';
                    d.pop_front();
                }
            }
            else
            {
                if(d.empty())
                {
                    std::cout << -1 << '\n';
                }
                else
                {
                    std::cout << d.back() << '\n';
                    d.pop_back();
                }
            }
        }
    }
    else if(str[0] == 's')
    {
       std::cout << d.size() << '\n';
    }
    else if(str[0] == 'e')
    {
       d.empty() ? std::cout << 1 << '\n' : std::cout << 0 << '\n';
    }
    else if(str[0] == 'f')
    {
       if(d.empty())
       {
           std::cout << -1 << '\n';
       }
       else
       {
           std::cout << d.front() << '\n';
       }
    }
    else if(str[0] == 'b')
    {
        if(d.empty())
       {
           std::cout << -1 << '\n';
       }
       else
       {
           std::cout << d.back() << '\n';
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