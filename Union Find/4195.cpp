#include <iostream>
#include <map>
#define MAX 200002

using namespace std;

int T, F;
int Parent[MAX];
int NumOfFriend[MAX];
map<string, int> HashMap;

int EmplaceName(int &index, string name)
{
    if (HashMap.find(name) == HashMap.end())
    {
        HashMap.emplace(name, index);
        ++index;
        return index - 1;
    }
    else
    {
        return HashMap.find(name)->second;
    }
}

int Find(int a)
{
    if (Parent[a] == a)
    {
        return a;
    }
    return Parent[a] = Find(Parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a > b)
    {
        Parent[a] = b;
        NumOfFriend[b] += NumOfFriend[a];
    }
    else
    {
        Parent[b] = a;
        NumOfFriend[a] += NumOfFriend[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        // Init Index, Parent, NumOfFriend, HashMap
        int index = 0; // index = NumOfAddedFriend
        for (int j = 0; j < MAX; ++j)
        {
            Parent[j] = j;
            NumOfFriend[j] = 1;
        }
        HashMap.clear();

        cin >> F;
        for (int j = 0; j < F; ++j)
        {
            string name1, name2;
            cin >> name1 >> name2;
            int NumberOfName1 = EmplaceName(index, name1);
            int NumberOfName2 = EmplaceName(index, name2);
            Union(NumberOfName1, NumberOfName2);
            cout << NumOfFriend[Find(NumberOfName1)] << '\n';
        }
    }
}