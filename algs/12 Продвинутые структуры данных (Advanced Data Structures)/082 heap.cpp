#include<iostream>
#include<vector>

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

int main()
{
    vector<int> heap(1);
    add(heap, 2);
    add(heap, 5);
    add(heap, 3);
    add(heap, 10);
    add(heap, 6);
    add(heap, 9);
    add(heap, 5);
    add(heap, 12);
    add(heap, 40);

    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
    erase(heap);
    cout << top(heap) << endl;
}



