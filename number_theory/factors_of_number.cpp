#include <bits/stdc++.h>

void factors(int n, std::vector<int> &result)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i != sqrt(n))
            {
                result.push_back(i);
                result.push_back(n / i);
            }
            else
            {
                result.push_back(i);
            }
        }
    }
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;

        std::cin >> n;

        std::vector<int> result;

        factors(n, result);

        for (auto item : result)
        {
            std::cout << item << " ";
        }

        std::cout << "\n";
    }

    return 0;
}
