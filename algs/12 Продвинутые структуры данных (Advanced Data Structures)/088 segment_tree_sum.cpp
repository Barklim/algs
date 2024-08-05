#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;
const int n = 8;
void build_tree(const vector<int>& a, int v = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        tree[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build_tree(a, v * 2, l, m);
    build_tree(a, v * 2 + 1, m + 1, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}
int sum(int i, int j, int v = 1, int l = 0, int r = n - 1)
{
    if (i > j)
        return 0;
    if (i == l && j == r)
    {
        return tree[v];
    }
    int m = (l + r) / 2;
    /*if (m >= j)
    {
        return sum(i, j, v * 2, l, m);
    }
    else if (m < i)
    {
        return sum(i, j, v * 2 + 1, m + 1, r);
    }
    else
    {
        return sum(i, m, v * 2, l, m) + sum(m + 1, j, v * 2 + 1, m + 1, r);
    }*/
    return sum(i, min(m, j), v * 2, l, m) + sum(max(m + 1, i), j, v * 2 + 1, m + 1, r);
}
void update(int i, int x, int v = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        tree[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m)
    {
        update(i, x, v * 2, l, m);
    }
    else
    {
        update(i, x, v * 2 + 1, m + 1, r);
    }
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int main()
{
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8 };
    tree.resize(4 * n);
    build_tree(a);
    std::cout << sum(1, 6) << std::endl;
    update(3, 10);
    std::cout << sum(1, 6) << std::endl;
}



