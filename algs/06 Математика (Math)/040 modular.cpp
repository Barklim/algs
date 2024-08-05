#include<iostream>

using namespace std;

long long bin_pow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= a;
            res %= mod;
        }
        n >>= 1;
        a *= a;
        a %= mod;
    }
    return res;
}


int main()
{
    // 5 * a == 4 mod 7
    long long mod = 1000000007; // [0, 1000000006]
    cout << 4 * bin_pow(5, mod - 2, mod) % mod;
}