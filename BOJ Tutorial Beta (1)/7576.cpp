#include <iostream>
#include <vector>
#include <queue>

int N, M;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool Finish(std::vector<int> board[])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool IsValid(int x,int y)
{
    if( x < 0 || x >= N || y < 0 || y >= M)
        return false;
    return true;
}

int BFS(std::vector<int> board[], std::vector<std::pair<int, int>> tomato)
{
    int date = 0;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < tomato.size(); ++i)
    {
        int x = tomato[i].first;
        int y = tomato[i].second;
        q.emplace(std::make_pair(x, y));
    }

    while (!q.empty())
    {
        if (Finish(board))
        {
            return date;
        }
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j=0; j<4; ++j)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
            
                if(IsValid(nx,ny) && board[nx][ny] == 0)
                {
                    board[nx][ny] = 1;
                    q.emplace(std::make_pair(nx,ny));
                }
            }
        }
        date++;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> M >> N;
    std::vector<int> board[N];
    std::vector<std::pair<int, int>> tomato;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int input;
            std::cin >> input;
            board[i].emplace_back(input);
            if (input == 1)
            {
                tomato.emplace_back(std::make_pair(i, j));
            }
        }
    }

    std::cout << BFS(board, tomato);
}