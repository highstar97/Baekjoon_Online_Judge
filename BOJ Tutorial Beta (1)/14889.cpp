#include <iostream>
#include <algorithm>
#include <vector>

int N;
int Min = 1000000000;

int GetScore(std::vector<int> v, int* data)
{
    int i=0; int j=0;
    int score = 0;
    for(auto data1 : v)
    {
        for(auto data2 : v)
        {
            if(data1 != data2)
            {
                score += *(data + data1*N + data2);
            }
        }
    }
    return score;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    int S[N][N];

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            std::cin >> S[i][j];
        }
    }

    std::string team;
    for(int i=0; i<N/2; ++i)
    {
        team += "1";
    }
    team.resize(N,'0');

    do
    {
        std::vector<int> start;
        std::vector<int> link;
        // 팀원 선별
        for(int i=0; i<N; ++i)
        {
            if(team[i] == '0')
            {
                start.emplace_back(i); 
            }
            else if(team[i] == '1')
            {
                link.emplace_back(i);
            }
        }
        int diff = abs(GetScore(start,(int*)S) - GetScore(link,(int*)S));
        diff < Min ? Min = diff : Min;
    }while(prev_permutation(team.begin(),team.end()));

    std::cout << Min;
    return 0;
}