#include <iostream>
#include <vector>
#include <algorithm>

int N, C;

int Binary_search(int start, int end, std::vector<int> home)
{
    int min = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int index = 0;
        int num = home[0];
        int count = 1;
        for (int i = 1; i < N; ++i)
        {
            if (home[i] >= num + mid)
            {
                index = i;
                num = home[i];
                ++count;
            }
        }

        if (count < C)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            min = std::max(min, mid);
        }
    }
    return min;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> C;
    std::vector<int> home(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> home[i];
    }
    std::sort(home.begin(), home.end());

    std::cout << Binary_search(1, *max_element(home.begin(), home.end()), home);
}