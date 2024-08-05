#include<iostream>
#include<vector>

using namespace std;

vector<int> sieve(int n)
{
    vector<bool> mark(n, true);
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2)
    {
        if (mark[i])
        {
            for (int j = i * i; j < n; j += i) // 2 * i, 3 * i, 4 * i, ...., (i - 1)*(i)
            {
                mark[j] = false;
            }
        }
    }
    for (int i = 3; i < n; i += 2)
        if (mark[i])
            primes.push_back(i);
    return primes;
}

int main()
{
    vector<int> primes = sieve(100);
    for (auto prime : primes)
    {
        cout << prime << " ";
    }
}