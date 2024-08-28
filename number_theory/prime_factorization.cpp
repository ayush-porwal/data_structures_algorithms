#include <cmath>
#include <vector>
#include <stdio.h>
#include <iostream>

void prime_factors(int n, std::vector<int> &result)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            result.push_back(i);
        }
    }

    if (n > 1)
    {
        result.push_back(n);
    }
}

int main()
{
    std::vector<int> result;

    prime_factors(48, result);

    for (auto factor : result)
    {
        std::cout << factor << " ";
    }

    return 0;
}
