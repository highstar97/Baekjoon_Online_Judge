#include <iostream>

int A, B, V;

int main()
{
    std::cin >> A >> B >> V;

    int day = (V - A) / (A - B);

    if ((V - A) % (A - B) != 0)
    {
        ++day;
    }

    std::cout << day + 1;
}