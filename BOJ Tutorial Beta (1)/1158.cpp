// queue를 이용한 최적화 코드
#include <iostream>
#include <queue>

int N,K;
std::queue<int> q;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;
    for(int i=1; i<=N; ++i)
    {
        q.emplace(i);
    }

    std::cout << "<";
    while(q.size()-1)
    {
        for(int i=0; i<K-1; ++i)
        {
            q.emplace(q.front());
            q.pop();
        }
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << q.front() << ">";
}

// 메모리를 많이 쓴 내 코드
/*
#include <iostream>
#include <set>
#include <vector>

int N,K;
std::string answer;
std::set<int> s;
std::vector<int> v;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;
    for(int i=1; i<=N; i++)
    {
        s.emplace(i);
        v.emplace_back(i);
    }

    int start = 0;
    answer += "<";
    while(!s.empty())
    {
        int erase_index = start+K-1;
        if(erase_index < v.size())
        {
            s.erase(s.find(v[erase_index]));
            answer += (std::to_string(v[erase_index])  + ", ");
            v.erase(v.begin()+erase_index);
            start = erase_index;
        }
        else
        {
            for(auto data : s)
            {
                v.emplace_back(data);
            }
        }
    }
    answer = answer.substr(0,answer.length()-2);
    answer += ">";
    std::cout << answer;
    return 0;
}*/