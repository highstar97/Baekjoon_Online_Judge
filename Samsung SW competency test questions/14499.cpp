#include <iostream>
#include <queue>

using namespace std;

int N, M, X, Y, K;
int Dice[6] = {0, 0, 0, 0, 0, 0}; // 위, 뒤, 오른, 왼, 앞, 아래
int drow[5] = {0, 0, 0, -1, 1};   // X, 동 서 북 남
int dcol[5] = {0, 1, -1, 0, 0};
int Map[20][20];
queue<int> qRoll;

enum Direction
{
    Up = 0,
    Back = 1,
    Right = 2,
    Left = 3,
    Front = 4,
    Down = 5
};

void Input()
{
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> Map[row][col];
        }
    }
    for (int i = 0; i < K; ++i)
    {
        int input;
        cin >> input;
        qRoll.emplace(input);
    }
    return;
}

void Solve()
{
    int CurrentRow = X;
    int CurrentCol = Y;
    while (!qRoll.empty())
    {
        int Dir = qRoll.front();
        qRoll.pop();

        int NextRow = CurrentRow + drow[Dir];
        int NextCol = CurrentCol + dcol[Dir];

        if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= M)
            continue;

        int CopyDice[6] = {Dice[Direction::Up], Dice[Direction::Back], Dice[Direction::Right], Dice[Direction::Left], Dice[Direction::Front], Dice[Direction::Down]};
        switch (Dir)
        {
        case (1): // 동
        {
            // 주사위를 오른쪽으로 굴렸다
            // 위 = 왼, 뒤 = 뒤, 오른 = 위, 왼 = 아래, 앞 = 앞, 아래 = 오른
            Dice[Direction::Up] = CopyDice[Direction::Left];
            Dice[Direction::Right] = CopyDice[Direction::Up];
            Dice[Direction::Left] = CopyDice[Direction::Down];
            Dice[Direction::Down] = CopyDice[Direction::Right];
            break;
        }
        case (2): // 서
        {
            // 주사위를 왼쪽으로 굴렸다.
            // 위 = 오른, 뒤 = 뒤, 오른 = 아래, 왼 = 위, 앞 = 앞, 아래 = 왼
            Dice[Direction::Up] = CopyDice[Direction::Right];
            Dice[Direction::Right] = CopyDice[Direction::Down];
            Dice[Direction::Left] = CopyDice[Direction::Up];
            Dice[Direction::Down] = CopyDice[Direction::Left];
            break;
        }
        case (3): // 북
        {
            // 주사위를 위쪽으로 굴렸다.
            // 위 = 앞, 뒤 = 위, 오른 = 오른, 왼 = 왼, 앞 = 아래, 아래 = 뒤
            Dice[Direction::Up] = CopyDice[Direction::Front];
            Dice[Direction::Back] = CopyDice[Direction::Up];
            Dice[Direction::Front] = CopyDice[Direction::Down];
            Dice[Direction::Down] = CopyDice[Direction::Back];
            break;
        }
        case (4): // 남
        {
            // 주사위를 아래쪽으로 굴렸다.
            // 위 = 뒤, 뒤 = 아래, 오른 = 오른, 왼 = 왼, 앞 = 위, 아래 = 앞
            Dice[Direction::Up] = CopyDice[Direction::Back];
            Dice[Direction::Back] = CopyDice[Direction::Down];
            Dice[Direction::Front] = CopyDice[Direction::Up];
            Dice[Direction::Down] = CopyDice[Direction::Front];
            break;
        }
        }

        if (Map[NextRow][NextCol] == 0)
        {
            Map[NextRow][NextCol] = Dice[Direction::Down];
        }
        else
        {
            Dice[Direction::Down] = Map[NextRow][NextCol];
            Map[NextRow][NextCol] = 0;
        }
        CurrentRow = NextRow;
        CurrentCol = NextCol;
        cout << Dice[Direction::Up] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X >> Y >> K;
    Input();

    Solve();
}