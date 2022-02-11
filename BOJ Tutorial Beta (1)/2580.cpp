#include <iostream>

bool IsValid(int Board[][9], int x, int y, int input)
{
    for (int i = 0; i < 9; ++i)
    {
        if (Board[x][i] == input)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        if (Board[i][y] == input)
        {
            return false;
        }
    }

    int start_x = (x / 3) * 3;
    int start_y = (y / 3) * 3;
    for (int i = start_x; i < start_x + 3; ++i)
    {
        for (int j = start_y; j < start_y + 3; ++j)
        {
            if (Board[i][j] == input)
            {
                return false;
            }
        }
    }
    return true;
}

void DFS(int Board[][9], int x, int y)
{
    if (y == 9)
    {
        ++x;
        y = 0;
    }

    if (x == 9 && y == 0)
    {
        std::cout << '\n';
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                std::cout << Board[i][j] << " ";
            }
            std::cout << '\n';
        }
        exit(0);
    }

    if (Board[x][y] == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (IsValid(Board, x, y, i))
            {
                Board[x][y] = i;
                DFS(Board, x, y + 1);
                Board[x][y] = 0;
            }
        }
    }
    else
    {
        DFS(Board,x,y+1);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int Board[9][9];
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::cin >> Board[i][j];
        }
    }

    DFS(Board, 0, 0);
}