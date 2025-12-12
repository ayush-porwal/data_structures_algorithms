#include <bits/stdc++.h>

using namespace std;

vector<bool> eratosthenes(int n)
{
    vector<bool> sieve(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            sieve[j] = true;
        }
    }

    return sieve;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<bool> sieve = eratosthenes(1000000);
    }

    return 0;
}