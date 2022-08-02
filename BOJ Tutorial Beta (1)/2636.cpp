#include <iostream>

int N,M;
int time = 0;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;
    int board[N][M];
    bool visited[N][M] = {false};
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    while(++time)
    {
        if(time == 1)
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j)
            {
                if(visited[i][j] == false)
                {

                }
            }
        }
    }
}