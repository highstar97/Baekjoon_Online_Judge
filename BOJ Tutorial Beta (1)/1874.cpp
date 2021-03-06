#include <iostream>
#include <stack>
#include <vector>

int N;
std::stack<int> s;
std::vector<int> input;
std::vector<std::string> result;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        int x;
        std::cin >> x;
        input.emplace_back(x);
    }

    int target_index = 0;

    for(int i=1; i<=N; ++i)
    {
        s.emplace(i);
        result.emplace_back("+");

        while(!s.empty() && s.top()==input[target_index])
        {
            s.pop();
            result.emplace_back("-");
            target_index++;
        }
    }

    if(!s.empty())
    {
        std::cout << "NO";
        return 0;
    }
    for(auto data : result)
    {
        std::cout << data << "\n";
    }
    return 0;
}


/* 안 좋은 풀이
#include <iostream>
#include <stack>
#include <vector>

int N;
std::stack<int> s, temp;
std::vector<std::string> answer;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    // temp에 역순으로 N ~ 1 까지 집어넣기 => temp = { N, N-1, ... 2, 1 }
    for(int i=N; i>0; --i)
    {
        temp.emplace(i);
    }

    while(N--)
    {
        int target;
        std::cin >> target;
        
        if(!temp.empty() && temp.top() <= target)
        {
            // push 해야 한다.
            while(temp.top() != target)
            {
                s.emplace(temp.top());
                temp.pop();
                answer.emplace_back("+");
            }
            temp.pop();
            answer.emplace_back("+");
            answer.emplace_back("-");
        }
        else
        {
            // 이미 push 했다.
            if(s.empty())
            {
                std::cout << "NO";
                return 0;
            }
            while(s.top() != target)
            {
                s.pop();
                answer.emplace_back("-");
                if(s.empty())
                {
                    std::cout << "NO";
                    return 0;
                }
            }
            s.pop();
            answer.emplace_back("-");
        }
    }

    for(auto data : answer)
    {
        std::cout << data << '\n';
    }
    return 0;
}*/