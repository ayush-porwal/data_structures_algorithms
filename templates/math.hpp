// Modulo Maths & Exponentiation

template <typename T>
T mod_add(T a, T b, int m)
{
    a %= m;
    b %= m;
    return (((a + b) % m) + m) % m;
}

template <typename T>
T mod_sub(T a, T b, int m)
{
    a %= m;
    b %= m;
    return (((a - b) % m) + m) % m;
}

template <typename T>
T mod_mul(T a, T b, int m)
{
    a %= m;
    b %= m;
    return (((a * b) % m) + m) % m;
}

template <typename T>
T bin_pow(T a, T b, int m)
{
    T result = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            result = mod_mul(result, a, m);
        }
        a = mod_mul(a, a, m);
        b >>= 1;
    }

    return result;
}

template <typename T>
T mod_inv_prime(T a, int m)
{
    return bin_pow(a, m - 2, m);
}

template <typename T>
T moddiv(T a, T b, int m)
{
    a %= m;
    b %= m;
    return (mod_mul(a, mod_inv_prime(b, m), m) + m) % m;
}

template <typename T>
void precomp_fact(T n, T m, vector<T> &fact, vector<T> &ifact)
{
    fact[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        fact[i] = mod_mul(fact[i - 1], i, m);
    }

    ifact[n] = bin_pow(fact[n], m - 2, m);

    for (int i = n - 1; i >= 0; i--)
    {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, m);
    }
}

template <typename T>
T ncr(T n, T r, T m, vector<T> &fact, vector<T> &ifact)
{
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);
}