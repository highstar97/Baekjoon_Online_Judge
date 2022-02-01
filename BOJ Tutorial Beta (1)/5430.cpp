#include <iostream>
#include <deque>
#include <vector>

int T;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> T;
    while (T--)
    {
        std::string p;
        int n;
        std::string arr;
        std::deque<int> dq;

        std::cin >> p;
        std::cin >> n;
        std::cin >> arr;

        std::string temp;
        for (int i = 0; i < arr.length(); ++i)
        {
            if (isdigit(arr[i]))
            {
                temp += arr[i];
            }
            else if (!temp.empty())
            {
                dq.emplace_back(stoi(temp));
                temp.clear();
            }
        }

        bool isReverse = false;
        bool isError = false;
        for (int i = 0; i < p.length(); ++i)
        {
            switch(p[i])
            {
            case ('R'):
            {
                isReverse = !isReverse;
                break;
            }
            case ('D'):
            {
                if (dq.empty())
                {
                    isError = true;
                }
                else
                {
                    isReverse ? dq.pop_back() : dq.pop_front();
                }
                break;
            }
            }
        }

        if (isError)
        {
            std::cout << "error" << '\n';
        }
        else if(dq.size() == 0)
        {
            std::cout << "[]\n";
        }
        else if (isReverse)
        {
            std::cout << "[";
            for (int i = dq.size() - 1; i > 0; --i)
            {
                std::cout << dq[i] << ",";
            }
            std::cout << dq[0] << "]\n";
        }
        else
        {
            std::cout << "[";
            for (int i = 0; i < dq.size() - 1; ++i)
            {
                std::cout << dq[i] << ",";
            }
            std::cout << dq[dq.size() - 1] << "]\n";
        }
    }
    return 0;
}