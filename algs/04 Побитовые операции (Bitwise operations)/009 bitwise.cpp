#include<iostream>

using namespace std;


int main()
{
    cout << (51 & 25) << endl; // 17
    cout << (51 | 25) << endl; // 59
    cout << (51 ^ 25) << endl; // 42
    cout << (~23u) << endl;
    cout << endl;
    cout << 12 << 2 << endl;
    cout << (12 << 2) << endl;
    cout << (12 >> 2) << endl;
    cout << (1 << 4) << endl;
    cout << (1 << 5) << endl;
    cout << (1 << 6) << endl;
    cout << (1 << 7) << endl;

    int n = 17; // 0...00010001
    int i = 2;
    n = n | (1 << i);
    cout << n << endl;
    n = n | (1 << i);
    cout << n << endl;
    n = n & ~(1 << i);
    cout << n << endl;
    n = n ^ (1 << i);
    cout << n << endl;
    n = n ^ (1 << i);
    cout << n << endl;
    n = n ^ (1 << i);
    cout << n << endl;
    n = n ^ (1 << i);
    cout << n << endl;
    n = n ^ (1 << i);
    cout << n << endl;

    if (n & (1 << i))
    {

    }
}