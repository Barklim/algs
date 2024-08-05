#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr{ 1, 7, 5, 3, 2, 3, 8, 9 };
    // 16, 17, 13, 16, 22
    int k = 4;
    int sum = 0;
    for (int i = 0; i < k; ++i) // O(k)
    {
        sum += arr[i];
    }
    cout << sum << "\n";
    for (int i = 1; i <= arr.size() - k; ++i) // O(n)
    {
        sum = sum - arr[i - 1] + arr[i + k - 1];
        cout << sum << "\n";
    }

    cout << "\n";
    cout << "\n";
    cout << "\n";

    for (int i = 0; i <= arr.size() - k; ++i) // O(n * k)
    {
        int sum = 0;
        for (int j = 0; j < k; ++j)
        {
            sum += arr[i + j];
        }
        cout << sum << "\n";
    }

}