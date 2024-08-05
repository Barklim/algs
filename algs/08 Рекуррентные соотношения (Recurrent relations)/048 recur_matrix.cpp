#include<iostream>
#include<vector>

using namespace std;

vector<vector<long long>> matrix_mul(const vector<vector<long long>>& a,
                                    const vector<vector<long long>>& b,
                                    long long mod)
{
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vector<vector<long long>> c(n, vector<long long>(k));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
            }
            c[i][j] %= mod;
        }
    }

    return c;
}
/*

2 ^ 30
1
1 0 0 
0 1 0
0 0 1

*/
vector<vector<long long>> bin_pow(vector<vector<long long>> a, long long n, long long mod)
{
    vector<vector<long long>> res(a.size(), vector<long long>(a.size()));
    for (int i = 0; i < res.size(); ++i)
        res[i][i] = 1;

    while (n)
    {
        if (n & 1)
        {
            // res *= a;
            res = matrix_mul(res, a, mod);
        }
        n >>= 1;
        a = matrix_mul(a, a, mod);
    }
    return res;
}

int main()
{
    vector<vector<long long>> fib_matrix{ 
        {1, 1}, 
        {1, 0} 
    };
    vector<vector<long long>> fib_first{
        {1, 0} // {f1, f0}
    };
    long long f1 = 1, f0 = 0;
    const int mod = 10000;
    for (int i = 1; i <= 1000; ++i)
    {
        // cout << "F(" << i << ") = " << fib_first[0][0] << endl;
        fib_first = matrix_mul(fib_first, fib_matrix, mod);

        long long f2 = (f1 + f0) % mod;
        f0 = f1;
        f1 = f2;


        if (f1 != fib_first[0][0])
        {
            std::cout << "ERROR: " << f1 << " " << fib_first[0][0] << endl;
        }
        auto matrix_pow = bin_pow(fib_matrix, i, mod);
        auto fibs = matrix_mul({ {1, 0} }, matrix_pow, mod);
        if (fibs[0][0] == fib_first[0][0])
        {
            std::cout << "RIGHT: " << fibs[0][0] << " " << fib_first[0][0] << endl;
        }
    }
    auto matrix_pow = bin_pow(fib_matrix, 1000000000000ll, mod);
    auto fibs = matrix_mul({ {1, 0} }, matrix_pow, mod);
    std::cout << fibs[0][0];
  
}