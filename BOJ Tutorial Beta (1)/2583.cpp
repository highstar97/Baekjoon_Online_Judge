#include <iostream>
#include <queue>

int M, N, K;
int board[100][100];
int visited[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool IsValid(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >= M)
        return false;
    return true;
}

int BFS(int i, int j)
{
    int num = 0;
    std::queue<std::pair<int,int>> q;
    q.emplace(std::make_pair(i,j));
    visited[i][j] = true;
    ++num;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(IsValid(nx,ny))
            {
                if(board[nx][ny] == 0 && visited[nx][ny] == false)
                {
                    q.emplace(std::make_pair(nx,ny));
                    visited[nx][ny] = true;
                    ++num;
                }
            }
        }
    }
    return num;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> M >> N >> K;
    // board, visited 초기화
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            board[i][j] = 0;
            visited[i][j] = false;
        }
    }
    // 입력 받기
    for(int i=0; i<K; ++i)
    {
        int x1,y1,x2,y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1; j<x2; ++j)
        {
            for(int k=y1; k<y2; ++k)
            {
                board[j][k] = 1;
            }
        }
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(board[i][j] == 0 && visited[i][j] == false)
            {
                pq.emplace(BFS(i,j));
            }
        }
    }
    std::cout << pq.size() << '\n';
    while(!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}