#include <iostream>
#include <vector>
#include <algorithm>

int N;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    std::vector<std::pair<int,int>> schedule(N);

    for(int i=0; i<N; ++i)
    {
        std::cin >> schedule[i].second >> schedule[i].first;
    }

    std::sort(schedule.begin(),schedule.end());

    int time = schedule[0].first;
    int count = 1;
    for(int i=1; i<N; ++i)
    {
        if(time <= schedule[i].second)
        {
            time = schedule[i].first;
            ++count;
        }
    }
    std::cout << count;
}