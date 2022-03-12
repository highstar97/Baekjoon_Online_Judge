#include <iostream>
#include <vector>
#include <queue>

int N, M, H;
int board[100][100][200]; // 면 H, 행 N, 열 M
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

struct location
{
    int x, y, z;
};

bool Finish()
{
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                if (board[i][j][k] == 0)
                    return false;
            }
        }
    }
    return true;
}

bool IsValid(int x, int y, int z)
{
    if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= H)
        return false;
    return true;
}

int BFS(std::vector<location> tomato)
{
    int date = 0;
    std::queue<location> q;
    for (int i = 0; i < tomato.size(); ++i)
    {
        q.emplace(tomato[i]);
    }

    while (!q.empty())
    {
        if (Finish())
        {
            return date;
        }
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();

            for (int j = 0; j < 6; ++j)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];

                if (IsValid(nx, ny, nz))
                {
                    if(board[nz][nx][ny] == 0)
                    {
                        board[nz][nx][ny] = 1;
                        location l;
                        l.x= nx; l.y = ny; l.z = nz;
                        q.emplace(l);
                        
                    }
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

    std::cin >> M >> N >> H;
    std::vector<location> tomato;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                std::cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                {
                    location l;
                    l.x = j;
                    l.y = k;
                    l.z = i;
                    tomato.emplace_back(l);
                }
            }
        }
    }

    std::cout << BFS(tomato);
}