#include<iostream>
#include<vector>

using namespace std;

bool binary_search(const vector<int>& arr, int x)
{
    int l = 0, r = arr.size() - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == x)
        {
            return true;
        }
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else if (arr[m] > x)
        {
            r = m - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> arr{ 1, 2, 4, 5, 7, 9, 12, 15, 19, 23 };
    std::cout << binary_search(arr, 7); // 1
    std::cout << binary_search(arr, 12); // 1
    std::cout << binary_search(arr, 23); // 1
    std::cout << binary_search(arr, 8); // 0
    std::cout << binary_search(arr, 3); // 0
    std::cout << binary_search(arr, -1); // 0
}