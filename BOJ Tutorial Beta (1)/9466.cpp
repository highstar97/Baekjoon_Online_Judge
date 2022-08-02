#include <iostream>
#include <vector>

int T, N;

bool DFS(int start, int current, int choice[], std::vector<int> visited[])
{
    for (int i = 0; i < visited[start].size(); ++i)
    {
        if (visited[start][i] == current)
            if(start == current)
                return true; // 사이클 존재
            else 
                return false;
    }

    visited[start].emplace_back(current);
    int next = choice[current];

    return DFS(start, next, choice, visited);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        int answer = N;
        int choice[N + 1];               // i번째 학생이 선택한 학생의 번호 저장
        std::vector<int> visited[N + 1]; // i번째 학생이 선택한 학생을 따라 갔을 때 방문한 학생들을 저장
        for (int i = 1; i <= N; ++i)
        {
            std::cin >> choice[i];
        }

        for (int i = 1; i <= N; ++i)
        {
            if (DFS(i, i, choice, visited))
                --answer;
        }
        std::cout << answer << "\n";
    }
}
