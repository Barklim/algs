#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<int> arr{ 1, 2, 3, 4, 5, 6, 7 };
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        bool first = true;
        cout << "{";
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                if (!first)
                    cout << ", ";
                first = false;
                cout << arr[i];
            }
        }
        cout << "}";
        cout << endl;
    }
}