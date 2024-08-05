#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> a{ 1,2,3,1,5,6,7,8 };

    vector<vector<int>> st(a.size(), vector<int>(log2(a.size()) + 1));

    for (int i = 0; i < a.size(); ++i)
    {
        st[i][0] = a[i]; // st[i][j] = [i; i + 2^j - 1]
    }

    for (int j = 1; j < st[0].size(); ++j)
        for (int i = 0; i + (1 << (j - 1)) < a.size(); ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    // st[i][j-1]                       // [i; i + 2^(j-1) - 1]
    // st[i + (1 << (j - 1))][j - 1]    // [i + 2^(j-1); i + 2^j - 1]

    int l = 1, r = 5;
    int j = log2(r - l + 1);
    cout << min(st[l][j], st[r - (1 << j) + 1][j]);
}