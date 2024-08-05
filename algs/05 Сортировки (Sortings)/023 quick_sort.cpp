#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int partition(vector<int>& arr, int i, int j)
{
    int pivot = rand() % (j - i) + i;
    swap(arr[pivot], arr[i]);
    pivot = i;
    int s1_index = i;
    int s2_index = i;
    for (int k = i + 1; k < j; ++k)
    {
        if (arr[k] >= arr[pivot])
        {
            ++s2_index;
        }
        else
        {
            ++s1_index;
            swap(arr[s1_index], arr[k]);
            ++s2_index;
        }
    } // 27 | 12 16 | 39 27 38
    //| 12 16 | 27 | 39 27 38 |
    swap(arr[pivot], arr[s1_index]);
    pivot = s1_index;
    return pivot;
}

void quick_sort(vector<int>& arr, int i, int j)
{
    if (i == j)
    {
        return;
    }
    int pivot = partition(arr, i, j); // [i, pivot - 1] < pivot // [pivot + 1, j] >= pivot
    quick_sort(arr, i, pivot);
    quick_sort(arr, pivot + 1, j);
}

void quick_sort(vector<int>& arr)
{
    quick_sort(arr, 0, arr.size());
}

// 5 10 15 20 25 30
// 5 | | 10 | | 15 20 25 30
// O(n ^ 2)
// O(n * log(n))
// O(1)

int main()
{
    vector<int> arr;
    const int n = rand() % 100;
    for (int i = 0; i < n; ++i)
        arr.push_back(rand());
    quick_sort(arr);

    vector<int> arr_copy = arr;
    sort(arr_copy.begin(), arr_copy.end());

    std::cout << (arr_copy == arr);
}