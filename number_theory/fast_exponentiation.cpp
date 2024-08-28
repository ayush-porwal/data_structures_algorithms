#include <bits/stdc++.h>

using namespace std;

long long fast_exp(long long a, long long b)
{
    long long res = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }

    return res;
}

// to calculate a^b mod m
long long fast_exp_mod(long long a, long long b, long long m)
{
    long long res = 1;

    a %= m;

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }

        a = a * a % m;

        b >>= 1;
    }

    return res;
}

int main()
{
    cout << fast_exp(3, 13);
    return 0;
}
