#include <iostream>
#include <vector>
#include <queue>

int N;
typedef std::vector<std::vector<int>> Board;

void MoveToDirection(std::queue<std::pair<Board,int>>& q, int d)
{
    Board next_board = q.front().first;
    switch(d)
    {
        case 0:
        {
            for(int j=0; j<N; j++)
            {
                for(int i=0; i<N; i++)
                {
                    for(int k=i+1; k<N; k++)
                    {
                        if(next_board[k][])
                        if(next_board[i][j] == next_board[k][j]);
                    }
                }
            }
        }
        case 1:
        {

        }
        case 2:
        {

        }
        case 3:
        {

        }
    }
}

int bfs(Board board)
{
    std::queue<std::pair<Board,int>> q;
    q.emplace(std::make_pair(board,0));

    while(!q.empty())
    {
        for(int i=0; i<4; i++)
        {
            MoveToDirection(q,i);
        }
    }
}

int main()
{
    std::cin >> N;
    Board board(N,std::vector<int> (N,0));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> board[i][j];
        }
    }

    return bfs(board);
}