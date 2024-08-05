#include<iostream>
#include<vector>
#include<string>

using namespace std;



// 319171894
int main()
{
    std::string s = "asdadqwezxcasdfqcsdfsf";
    std::vector<long long> hashes(s.size() + 1);
    hashes[0] = 0;
    std::vector<long long> primes(s.size() + 1);
    primes[0] = 1;

    const int p = 301;
    const int m = 1e9 + 7;

    for (int i = 0; i < s.size(); ++i)
    {
        hashes[i + 1] = hashes[i] * p + (s[i] - 'a' + 1);
        hashes[i + 1] %= m;
        primes[i + 1] = primes[i] * p;
        primes[i + 1] %= m;
    }

    int i = 3, j = 7; // adqwe

    long long substr_hash = (hashes[j + 1] - (hashes[i] * primes[j - i + 1]) % m) % m;
    if (substr_hash < 0)
        substr_hash += m;


    cout << substr_hash << endl;


}