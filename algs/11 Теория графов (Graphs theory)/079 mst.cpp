#include<iostream>
#include<vector>
#include<algorithm>

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

struct edge
{
    int a, b, c;
    bool operator<(const edge& e)
    {
        return c < e.c;
    }
};

int main()
{
    parent.resize(7);
    sizes.resize(7);
    for (int i = 0; i < parent.size(); ++i)
    {
        parent[i] = i;
        sizes[i] = 1;
    }

    vector<edge> edges{
        {1, 2, 5},
        {1, 3, 9},
        {1, 5, 1},
        {1, 6, 3},
        {2, 4, 8},
        {2, 6, 3},
        {3, 5, 4},
        {4, 6, 7},
        {5, 6, 2},
    };

    sort(edges.begin(), edges.end());

    int all_cost = 0;

    for (int i = 0; i < edges.size(); ++i)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int c = edges[i].c;
        if (find_set(a) != find_set(b))
        {
            cout << a << " " << b << "\n";
            all_cost += c;
            union_set(a, b);
        }
    }
    cout << all_cost << endl;
}