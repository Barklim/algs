#include<iostream>
#include<vector>

using namespace std;

void dfs_list(const vector<vector<int>>& graph,
                vector<int>& used,
                int current_vertex)
{
    cout << current_vertex + 1 << " ";
    used[current_vertex] = 1;
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        int adjacent_vertex = graph[current_vertex][i];
        if (used[adjacent_vertex] != 1)
        {
            dfs_list(graph, used, adjacent_vertex);
        }
    }
}

void dfs_matrix(const vector<vector<int>>& graph,
                vector<int>& used,
                int current_vertex)
{
    cout << current_vertex + 1 << " ";
    used[current_vertex] = 1;
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        if (graph[current_vertex][i] == 1)
        {
            if (used[i] != 1)
            {
                dfs_matrix(graph, used, i);
            }
        }
    }
}

int main()
{
    vector<vector<int>> adjacency_list{
        {1, 3},
        {0, 5, 6},
        {6},
        {0, 4},
        {3, 7},
        {1, 6},
        {1, 2, 5},
        {4}
    };

    vector<vector<int>> adjacency_matrix{
        {0, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
    };
    const int n = 8;
    vector<int> used(n);
    dfs_list(adjacency_list, used, 0);
    cout << endl;
    used.assign(n, 0);
    dfs_matrix(adjacency_matrix, used, 0);
}