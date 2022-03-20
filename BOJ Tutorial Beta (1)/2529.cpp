#include <iostream>
#include <vector>
#include <algorithm>

int K;

bool isValid(std::vector<int> v, char exp[])
{
    for (int i = 0; i < K; ++i)
    {
        if (exp[i] == '<' && v[i] > v[i + 1])
        {
            return false;
        }
        if (exp[i] == '>' && v[i] < v[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cin >> K;
    char exp[K];
    std::vector<int> min;
    std::vector<int> max;

    for (int i = 0; i < K; ++i)
    {
        std::cin >> exp[i];
    }

    for (int i = 0; i <= K; ++i)
    {
        min.emplace_back(i);
        max.emplace_back(9 - i);
    }

    do
    {
        if (isValid(max, exp))
        {
            for (int i = 0; i <= K; ++i)
            {
                std::cout << max[i];
            }
            std::cout << '\n';
            break;
        }
    } while (prev_permutation(max.begin(), max.end()));

    do
    {
        if (isValid(min, exp))
        {
            for (int i = 0; i <= K; ++i)
            {
                std::cout << min[i];
            }
            std::cout << '\n';
            break;
        }
    } while (next_permutation(min.begin(), min.end()));
}