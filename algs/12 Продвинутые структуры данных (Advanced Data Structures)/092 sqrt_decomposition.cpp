#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8 };

    int s = sqrt(a.size());
    ++s;

    vector<int> b(s);
    for (int i = 0; i < a.size(); ++i)
    {
        b[i / s] += a[i];
    }

    int l = 1, r = 6; // 27

    int sum = 0;
    for (int i = l; i <= r;)
    {
        if (i % s == 0 && i + s - 1 <= r)
        {
            sum += b[i / s];
            i += s;
        }
        else
        {
            sum += a[i];
            ++i;
        }
    }
    cout << sum;

}



