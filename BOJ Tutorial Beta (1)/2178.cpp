#include <iostream>
#include <vector>
#include <queue>

int N, M, answer = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS(int row, int col, std::vector<std::vector<char>> map, std::vector<std::vector<bool>> &visited)
{
    std::queue<std::pair<int, int>> q;
    q.emplace(std::make_pair(row, col));
    visited[row][col] = true;

    while (!q.empty())
    {
        int size = q.size();
        for (int i=0; i<size; ++i)
        {
            if(q.front().first == N-1 && q.front().second == M-1)
            {
                answer++;
                return;
            }
            for(int j=0; j<4; ++j)
            {
                int nx = q.front().first + dx[j];
                int ny = q.front().second + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                else if (map[nx][ny] == '1' && !visited[nx][ny])
                {
                    q.emplace(std::make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
            q.pop();
        }
        answer++;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N >> M;

    std::vector<std::vector<char>> map(N, std::vector<char>(M, '0'));
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
    {
        std::string temp;
        std::cin >> temp;
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = temp[j];
        }
    }
    BFS(0, 0, map, visited);
    std::cout << answer;
}