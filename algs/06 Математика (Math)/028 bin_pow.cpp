#include<iostream>

using namespace std;

int bin_pow1(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 1)
    {
        return bin_pow1(a, n - 1) * a;
    }
    int b = bin_pow1(a, n / 2);
    return b * b;
}

int bin_pow2(int a, int n)
{
    int result = 1;
    while (n != 0)
    {
        if (n & 1)
        {
            result *= a;
        }
        n >>= 1;
        a *= a;
        // a, a^2, a^4, a^8, ...
    }
    return result;
}

int main()
{
    std::cout << (bin_pow2(2, 10) == 1024);
    std::cout << (bin_pow2(3, 5) == 243);
    std::cout << (bin_pow2(3, 15) == 14348907);
    std::cout << (bin_pow2(2, 7) == 64);
    std::cout << (bin_pow2(2, 7) == 128);
}