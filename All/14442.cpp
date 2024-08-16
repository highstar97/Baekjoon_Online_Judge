/*
    벽 부수고 이동하기, 벽 K번 부수기 가능
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, Answer;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int Map[1000][1000];

struct Node
{
    int row, col, Distance, NumOfBreak;

    Node() = default;
    Node(int row, int col, int Distance, int NumOfBreak) : row(row), col(col), Distance(Distance), NumOfBreak(NumOfBreak) {};
};

int BFS()
{
    queue<Node> Queue;
    vector<vector<vector<bool>>> IsVisited(K + 1, vector<vector<bool>>(N, vector<bool>(M, false)));
    Queue.emplace(Node(0, 0, 1, 0));
    IsVisited[0][0][0] = true;

    while (!Queue.empty())
    {
        Node CurrentNode = Queue.front();
        Queue.pop();

        if (CurrentNode.row == N - 1 && CurrentNode.col == M - 1)
            return CurrentNode.Distance;

        Node NextNode;
        for (int k = 0; k < 4; ++k)
        {
            NextNode.row = CurrentNode.row + drow[k];
            NextNode.col = CurrentNode.col + dcol[k];

            if (NextNode.row < 0 || NextNode.row >= N || NextNode.col < 0 || NextNode.col >= M)
                continue;

            if (Map[NextNode.row][NextNode.col] == 0)
            {
                if (IsVisited[CurrentNode.NumOfBreak][NextNode.row][NextNode.col])
                    continue;
                Queue.emplace(Node(NextNode.row, NextNode.col, CurrentNode.Distance + 1, CurrentNode.NumOfBreak));
                IsVisited[CurrentNode.NumOfBreak][NextNode.row][NextNode.col] = true;
            }
            else
            {
                if (CurrentNode.NumOfBreak == K || IsVisited[CurrentNode.NumOfBreak + 1][NextNode.row][NextNode.col])
                    continue;
                Queue.emplace(Node(NextNode.row, NextNode.col, CurrentNode.Distance + 1, CurrentNode.NumOfBreak + 1));
                IsVisited[CurrentNode.NumOfBreak + 1][NextNode.row][NextNode.col] = true;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; ++j)
        {
            char input_char = input[j] - '0';
            Map[i][j] = input_char;
        }
    }

    cout << BFS();
}