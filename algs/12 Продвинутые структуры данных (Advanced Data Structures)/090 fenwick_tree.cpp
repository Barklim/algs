#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;
const int n = 8;

void update(int i, int x) // h(x) = x | (x + 1)
{
    for (int j = i; j < n; j = j | (j + 1))
    {
        tree[j] += x;
    }
}

void build_tree(const vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        update(i, a[i]);
    }
}

int sum(int r) // [0; r]
{
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
    {
        result += tree[r];
    }
    return result;
}

int sum(int l, int r) // [l; r]
{
    return sum(r) - sum(l - 1);
}


int main()
{
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8 };
    tree.resize(n);
    build_tree(a);
    std::cout << sum(1, 6) << std::endl; // 27 
    update(3, 10);
    std::cout << sum(1, 6) << std::endl; // 37
}