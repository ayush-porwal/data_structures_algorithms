#include <bits/stdc++.h>

using namespace std;

const int IMAX = 1e6;
const int mod = 1e9 + 7;

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

void factorial(vector<int> &fac, int mod)
{
    fac[0] = 1;

    for (int i = 1; i <= IMAX; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
}

void inverse(vector<int> &inv, vector<int> &fac, int mod)
{
    inv[IMAX] = fast_exp_mod(fac[IMAX], mod - 2, mod);

    for (int i = IMAX; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % mod;
    }
}

int main()
{
    int t;

    cin >> t;

    vector<int> fac(IMAX + 1, 0);
    vector<int> inv(IMAX + 1, 0);

    factorial(fac, mod);
    inverse(inv, fac, mod);

    while (t--)
    {
        int n, r;

        cin >> n >> r;

        cout << fac[n] * inv[n - r] % mod * inv[r] % mod << "\n";
    }

    return 0;
}