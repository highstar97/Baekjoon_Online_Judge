#include <iostream>
#include <queue>
#include <vector>

int N, M;
char board[1000][1000];
int visited[1000][1000][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// board 인덱스 초과 확인
bool IsValid(int x, int y)
{
    if (0 <= x && x < N)
        if (0 <= y && y < M)
            return true;
    return false;
}

int BFS()
{
    // x, y, 벽뚫기 가능 횟수
    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.emplace(std::make_pair(std::make_pair(0, 0), 1));
    visited[0][0][1] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int canbreak = q.front().second;
        // 목적지에 도달한 경우 BFS 종료
        if (x == N - 1 && y == M - 1)
        {
            return visited[x][y][canbreak];
        }
        for (int j = 0; j < 4; ++j)
        {
            int next_x = x + dx[j];
            int next_y = y + dy[j];

            if (IsValid(next_x, next_y))
            {
                // 벽이 아니고 방문하지 않은 곳
                if (board[next_x][next_y] == '0' && visited[next_x][next_y][canbreak] == 0)
                {
                    visited[next_x][next_y][canbreak] = visited[x][y][canbreak] + 1;
                    q.emplace(std::make_pair(std::make_pair(next_x, next_y), canbreak));
                    //std::cout << next_x << " " << next_y << " " << canbreak << '\n';
                }
                // 벽이지만 방문하지 않았고 부술 기회가 남았다면
                if (board[next_x][next_y] == '1' && canbreak == 1)
                {
                    visited[next_x][next_y][0] = visited[x][y][canbreak] + 1;
                    q.emplace(std::make_pair(std::make_pair(next_x, next_y), 0));
                    //std::cout << next_x << " " << next_y << " 0" << '\n';
                }
            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = input[j];
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }

    std::cout << BFS();
}