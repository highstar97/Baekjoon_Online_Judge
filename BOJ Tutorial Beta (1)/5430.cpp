#include <iostream>
#include <vector>
#include <deque>

int T, n;
bool isReverse, isError;
std::string p;
std::string str_num;
std::deque<int> dq;

void Initialize()
{
    n = 0;
    isReverse = false;
    isError = false;
    p.clear();
    str_num.clear();
    dq.clear();
}

void PushOnlyIntToDeque()
{
    std::string temp;
    for(int i=0; i<str_num.length(); ++i)
    {
        if(isdigit(str_num[i]))
        {
            temp += str_num[i];
        }
        else if(!temp.empty())
        {
            dq.push_back(stoi(temp));
            temp.clear();
        }
    }
}

void Readp()
{
    for (int i = 0; i < p.length(); ++i)
    {
        switch (p[i])
        {
        case ('R'):
        {
            isReverse = !isReverse;
            break;
        }
        case ('D'):
        {
            if(dq.empty())
            {
                isError = true;
            }
            else if (!isReverse)
            {
                dq.pop_front();
            }
            else
            {
                dq.pop_back();
            }
            break;
        }
        }
    }
}

void Print()
{
    if(isError)
    {
        std::cout << "error" << '\n';
        return ;
    }
    else if( n==0 )
    {
        std::cout << "[]" << '\n';
        return ;
    }
    std::cout << "[";
    if(!isReverse)
    {
        for(auto it = dq.begin(); it != dq.end()-1; ++it)
        {
            std::cout << *it << ",";
        }
        std::cout << *(dq.end()-1);
    }
    else
    {
        for (auto it = dq.rbegin(); it != dq.rend()-1; ++it)
        {
            std:: cout << *it << ",";
        }
        std::cout << *(dq.rend()-1);
    }
    std::cout << "]" << '\n';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> T;
    while (T--)
    {
        Initialize();

        std::cin >> p;
        std::cin >> n;
        std::cin >> str_num;

        PushOnlyIntToDeque();

        Readp();

        Print();
    }
    return 0;
}