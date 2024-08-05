#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void add(vector<int>& heap, int x) // O(log(n))
{
    heap.push_back(x);
    int ind = heap.size() - 1;
    while (ind != 1 && heap[ind] < heap[ind / 2])
    {
        swap(heap[ind], heap[ind / 2]);
        ind /= 2;
    }
}

void erase(vector<int>& heap) // O(log(n))
{
    swap(heap[1], heap[heap.size() - 1]);
    heap.pop_back();
    int ind = 1;
    while (ind * 2 < heap.size() && heap[ind] > heap[ind * 2] ||
        ind * 2 + 1 < heap.size() && heap[ind] > heap[ind * 2 + 1])
    {
        if (ind * 2 + 1 >= heap.size() || heap[ind * 2] < heap[ind * 2 + 1])
        {
            swap(heap[ind], heap[ind * 2]);
            ind *= 2;
        }
        else
        {
            swap(heap[ind], heap[ind * 2 + 1]);
            ind *= 2;
            ++ind;
        }
    }

}

int top(vector<int>& heap) // O(1)
{
    return heap[1];
}

int empty(vector<int>& heap) // O(1)
{
    return heap.size() == 1;
}

void heap_sort(vector<int>& arr)
{
    vector<int> heap(1);
    for (int i = 0; i < arr.size(); ++i)
    {
        add(heap, arr[i]);
    }
    arr.clear();
    while (!empty(heap))
    {
        arr.push_back(top(heap));
        erase(heap);
    }
}

int main()
{
    vector<int> arr;
    const int n = rand() % 100;
    for (int i = 0; i < n; ++i)
        arr.push_back(rand());
    heap_sort(arr);

    vector<int> arr_copy = arr;
    sort(arr_copy.begin(), arr_copy.end());

    std::cout << (arr_copy == arr);
}


