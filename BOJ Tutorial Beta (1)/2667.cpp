#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
std::vector<int> answer;

bool IsValid(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    char board[N][N];
    bool visited[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> board[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == '1' && visited[i][j] == false)
            {
                // BFS(board,visited)
                int n = 0;
                std::queue<std::pair<int, int>> q;
                q.emplace(std::make_pair(i, j));
                visited[i][j] = true;
                ++n;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int nx = x + dx[j];
                        int ny = y + dy[j];

                        if (IsValid(nx, ny))
                        {
                            if (board[nx][ny] == '1' && visited[nx][ny] == false)
                            {
                                q.emplace(std::make_pair(nx, ny));
                                visited[nx][ny] = true;
                                ++n;
                            }
                        }
                    }
                }
                answer.emplace_back(n);
            }
        }
    }
    std::sort(answer.begin(),answer.end());
    std::cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); ++i)
    {
        std::cout << answer[i] << "\n";
    }
}