#include <iostream>
#define MAX 1000001

using namespace std;

int N, M;
int Parent[MAX];

int Find(int a)
{
    if (Parent[a] == a)
    {
        return a;
    }

    return Parent[a] = Find(Parent[a]);
}

// Make Smallest Number To Parent
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    a > b ? Parent[a] = b : Parent[b] = a;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    // Init Parent
    for (int i = 0; i <= N; ++i)
    {
        Parent[i] = i;
    }

    // Solve
    for (int i = 0; i < M; ++i)
    {
        int key, a, b;
        cin >> key >> a >> b;

        if (key == 0)
        {
            Union(a, b);
        }
        else if (key == 1)
        {
            if (Find(a) == Find(b))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}