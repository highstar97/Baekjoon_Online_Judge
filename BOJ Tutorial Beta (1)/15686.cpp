#include <iostream>
#include <vector>
#include <algorithm>

struct Location
{
    int x; int y;
};

int N, M;
int answer = 1000000000;
std::vector<Location> home;
std::vector<Location> store;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;
    for(int i=0; i<N; ++i) // 집과 치킨집 구분
    {
        for(int j=0; j<N; ++j)
        {
            int input;
            Location l;
            l.x = i; l.y = j;    
            std::cin >> input;
            switch(input)
            {
                case (1):
                {
                    home.emplace_back(l);
                    break;
                }
                case (2):
                {
                    store.emplace_back(l);
                    break;
                }
                default:
                {
                    break;
                }
            }
       }
    }

    int length[home.size()][store.size()];
    for(int i=0; i<home.size(); ++i)
    {
        for(int j=0; j<store.size(); ++j)
        {
            length[i][j] = abs(home[i].x - store[j].x) + abs(home[i].y - store[j].y);
        }
    }

    std::string bitmask;
    for(int i=0; i<M; ++i)
    {
        bitmask += "1";
    }
    bitmask.resize(store.size(),'0');

    do
    {
        int temp_answer = 0;
        int final_length[home.size()];
        std::fill_n(final_length,home.size(),1000000000);   // 10억 10억 10억 10억
        for(int i=0; i<bitmask.length(); ++i)
        {
            if(bitmask[i] == '1')
            {
                for(int j=0; j<home.size(); ++j)
                {
                    if(length[j][i] < final_length[j])
                    {
                        final_length[j] = length[j][i];
                    }
                }
            }
        }
        for(int i=0; i<home.size(); ++i)
        {
            temp_answer += final_length[i];
        }
        if(temp_answer < answer)
        {
            answer = temp_answer;
        }
    }while(prev_permutation(bitmask.begin(), bitmask.end()));
    std::cout << answer;
    return 0;
}