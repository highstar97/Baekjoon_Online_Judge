#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, Answer;

void Print(vector<vector<int>> Board)
{
    cout << "------------------------------\n";
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            cout << Board[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------\n";
}

vector<vector<int>> Up(vector<vector<int>> Board)
{
    for (int col = 0; col < N; ++col)
    {
        queue<int> Queue;
        for (int row = 0; row < N; ++row)
        {
            if (Board[row][col] == 0)
                continue;
            Queue.emplace(Board[row][col]);
            Board[row][col] = 0;
        }

        for (int row = 0; row < N; ++row)
        {
            if (Queue.size() >= 2)
            {
                int first = Queue.front();
                Queue.pop();
                int second = Queue.front();

                if (first == second)
                {
                    Board[row][col] = first * 2;
                    Queue.pop();
                }
                else
                {
                    Board[row][col] = first;
                }
            }
            else if (Queue.size() == 1)
            {
                Board[row][col] = Queue.front();
                Queue.pop();
            }
            else // Queue.size() == 0
            {
                break;
            }
        }
    }
    return Board;
}
vector<vector<int>> Down(vector<vector<int>> Board)
{
    for (int col = 0; col < N; ++col)
    {
        queue<int> Queue;
        for (int row = N - 1; row >= 0; --row)
        {
            if (Board[row][col] == 0)
                continue;
            Queue.emplace(Board[row][col]);
            Board[row][col] = 0;
        }

        for (int row = N - 1; row >= 0; --row)
        {
            if (Queue.size() >= 2)
            {
                int first = Queue.front();
                Queue.pop();
                int second = Queue.front();

                if (first == second)
                {
                    Board[row][col] = first * 2;
                    Queue.pop();
                }
                else
                {
                    Board[row][col] = first;
                }
            }
            else if (Queue.size() == 1)
            {
                Board[row][col] = Queue.front();
                Queue.pop();
            }
            else // Queue.size() == 0
            {
                break;
            }
        }
    }
    return Board;
}
vector<vector<int>> Left(vector<vector<int>> Board)
{
    for (int row = 0; row < N; ++row)
    {
        queue<int> Queue;
        for (int col = 0; col < N; ++col)
        {
            if (Board[row][col] == 0)
                continue;
            Queue.emplace(Board[row][col]);
            Board[row][col] = 0;
        }

        for (int col = 0; col < N; ++col)
        {
            if (Queue.size() >= 2)
            {
                int first = Queue.front();
                Queue.pop();
                int second = Queue.front();

                if (first == second)
                {
                    Board[row][col] = first * 2;
                    Queue.pop();
                }
                else
                {
                    Board[row][col] = first;
                }
            }
            else if (Queue.size() == 1)
            {
                Board[row][col] = Queue.front();
                Queue.pop();
            }
            else // Queue.size() == 0
            {
                break;
            }
        }
    }
    return Board;
}
vector<vector<int>> Right(vector<vector<int>> Board)
{
    for (int row = 0; row < N; ++row)
    {
        queue<int> Queue;
        for (int col = N - 1; col >= 0; --col)
        {
            if (Board[row][col] == 0)
                continue;
            Queue.emplace(Board[row][col]);
            Board[row][col] = 0;
        }

        for (int col = N - 1; col >= 0; --col)
        {
            if (Queue.size() >= 2)
            {
                int first = Queue.front();
                Queue.pop();
                int second = Queue.front();

                if (first == second)
                {
                    Board[row][col] = first * 2;
                    Queue.pop();
                }
                else
                {
                    Board[row][col] = first;
                }
            }
            else if (Queue.size() == 1)
            {
                Board[row][col] = Queue.front();
                Queue.pop();
            }
            else // Queue.size() == 0
            {
                break;
            }
        }
    }
    return Board;
}

void DFS(int Depth, vector<vector<int>> Board)
{
    if (Depth == 5)
    {
        for (int row = 0; row < N; ++row)
        {
            for (int col = 0; col < N; ++col)
            {
                Answer = max(Answer, Board[row][col]);
            }
        }
        return;
    }

    DFS(Depth + 1, Up(Board));
    DFS(Depth + 1, Down(Board));
    DFS(Depth + 1, Left(Board));
    DFS(Depth + 1, Right(Board));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> Board(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
        }
    }

    DFS(0, Board);
    cout << Answer << endl;
}