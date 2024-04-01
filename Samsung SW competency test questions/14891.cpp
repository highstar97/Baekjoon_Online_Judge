#include <iostream>
#include <vector>
#include <deque>
#include <math.h>

using namespace std;

int K;
int Rotation[5];
bool IsRotate[5];
vector<deque<int>> Gear(5, deque<int>(8, 0));

void SetRotation(int Number, int Dir)
{
    Rotation[Number] = Dir;
    IsRotate[Number] = true;

    if (Number - 1 > 0 && IsRotate[Number - 1] == false)
    {
        if (Dir == 0)
        {
            SetRotation(Number - 1, 0);
        }
        else if (Gear[Number][6] == Gear[Number - 1][2])
        {
            SetRotation(Number - 1, 0);
        }
        else
        {
            SetRotation(Number - 1, -Dir);
        }
    }

    if (Number + 1 <= 4 && IsRotate[Number + 1] == false)
    {
        if (Dir == 0)
        {
            SetRotation(Number + 1, 0);
        }
        else if (Gear[Number][2] == Gear[Number + 1][6])
        {
            SetRotation(Number + 1, 0);
        }
        else
        {
            SetRotation(Number + 1, -Dir);
        }
    }
}

void Rotate()
{
    for (int i = 1; i <= 4; ++i)
    {
        if (Rotation[i] == 0)
        {
            continue;
        }
        else if (Rotation[i] == 1)
        {
            int Temp = Gear[i].back();
            Gear[i].pop_back();
            Gear[i].push_front(Temp);
        }
        else
        {
            int Temp = Gear[i].front();
            Gear[i].pop_front();
            Gear[i].push_back(Temp);
        }
    }
}

int GetScore()
{
    int Answer = 0;
    for (int i = 1; i <= 4; ++i)
    {
        if (Gear[i][0] == 1)
        {
            Answer += pow(2, i - 1);
        }
    }
    return Answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 4; ++i)
    {
        string Input;
        cin >> Input;
        for (int j = 0; j < 8; ++j)
        {
            Gear[i][j] = Input[j] - '0';
        }
    }

    cin >> K;
    while (K--)
    {
        int Number, Dir;
        cin >> Number >> Dir;
        fill_n(IsRotate, 5, false);
        SetRotation(Number, Dir);
        Rotate();
    }

    cout << GetScore() << endl;
}