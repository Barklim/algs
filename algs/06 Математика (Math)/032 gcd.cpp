#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    std::cout << (gcd(15, 24) == 3);
    std::cout << (gcd(7, 14) == 7);
    std::cout << (gcd(14, 7) == 7);
    std::cout << (gcd(15, 28) == 1);

    std::cout << (lcm(15, 24) == 120);
    std::cout << (lcm(7, 14) == 14);
    std::cout << (lcm(14, 7) == 14);
    std::cout << (lcm(15, 28) == 15 * 28);
}
