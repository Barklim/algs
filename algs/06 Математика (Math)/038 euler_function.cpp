#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int euler(int n) // O(n * log(n))
{
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (gcd(i, n) == 1)
        {
            count++;
        }
    }
    return count;
}

int euler_fast(int n) // O(sqrt(n))
{
    int result = n;
    int prime = 2;
    while (n >= prime * prime)
    {
        if (n % prime == 0)
        {
            result = result / prime * (prime - 1); // (1 - 1/p) = (p-1)/p
            while (n % prime == 0)
            {
                n /= prime;
            }
        }
        ++prime;
    }
    if (n != 1)
    {
        result = result / n * (n - 1);
    }
    return result;
}

int main()
{
    cout << (euler(9) == 6);
    cout << (euler_fast(9) == 6);

    cout << (euler(36) == 12);
    cout << (euler_fast(36) == 12);
    
    cout << (euler(84) == 24);
    cout << (euler_fast(84) == 24);
}