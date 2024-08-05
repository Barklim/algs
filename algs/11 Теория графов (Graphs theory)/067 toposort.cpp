#include<iostream>
#include<vector>

using namespace std;

void dfs(const vector<vector<int>>& graph,
        vector<int>& used,
        vector<int>& order,
        int current_vertex)
{
    used[current_vertex] = 1;
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        int adjacent_vertex = graph[current_vertex][i];
        if (used[adjacent_vertex] != 1)
        {
            dfs(graph, used, order, adjacent_vertex);
        }
    }
    order.push_back(current_vertex);
}

int main()
{
    vector<vector<int>> graph{
        {4},
        {0},
        {3, 1},
        {0, 1, 4},
        {},
    };

    vector<int> used(graph.size());
    vector<int> order;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (!used[i])
        {
            dfs(graph, used, order, i);
        }
    };
    reverse(order.begin(), order.end());
    for (int i = 0; i < graph.size(); ++i)
    {
        cout << i + 1 << " -> " << order[i] + 1 << endl;
    }
}