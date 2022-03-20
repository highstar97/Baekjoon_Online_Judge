#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> tree;

int Binary_search(int start, int end)
{
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        long long sum = 0;
        for (int i = 0; i < N; ++i)
        {
            if (tree[i] > mid)
            {
                sum += tree[i] - mid;
            }
        }

        if (sum >= M)
        {
            start = mid + 1;
            answer = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int input;
        std::cin >> input;
        tree.emplace_back(input);
    }

    std::cout << Binary_search(0, *max_element(tree.begin(), tree.end()));
}