#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;
vector<int> sizes;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

int main()
{
    parent.resize(10);
    sizes.resize(10, 1);
    for (int i = 0; i < parent.size(); ++i)
    {
        parent[i] = i;
    }

    cout << find_set(0) << endl;
    cout << find_set(1) << endl;
    union_set(0, 1);

    cout << find_set(0) << endl;
    cout << find_set(1) << endl;
    
    union_set(1, 2);
    union_set(2, 3);
    union_set(3, 4);
    union_set(4, 5);

    cout << find_set(0) << endl;
    cout << find_set(1) << endl;
    cout << find_set(2) << endl;
    cout << find_set(3) << endl;
    cout << find_set(4) << endl;
    cout << find_set(5) << endl;
    cout << find_set(6) << endl;
}