#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> L; // O(n)
    L.push_back(1);

    for (int i = 1; i <= n; ++i) // O(k * n)
    {
        long long temp = 0;
        for (int j = 0; j < k; ++j)
        {
            if (L.size() < 1 + j)
            {
                break;
            }
            temp += L[L.size() - 1 - j];
            temp %= 10000;
        }
        L.push_back(temp);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << L[i] << " ";
    }

}




