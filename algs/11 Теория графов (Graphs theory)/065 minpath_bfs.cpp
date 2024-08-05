#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start_vertex)
{
    vector<int> used(graph.size(), -1);
    used[start_vertex] = 0;
    queue<int> q;
    q.push(start_vertex);

    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop();
        std::cout << current_vertex + 1 << " ";
        for (int i = 0; i < graph[current_vertex].size(); ++i)
        {
            int adjacent_vertex = graph[current_vertex][i];
            if (used[adjacent_vertex] == -1)
            {
                q.push(adjacent_vertex);
                used[adjacent_vertex] = used[current_vertex] + 1;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < used.size(); ++i)
    {
        cout << i + 1 << " " << used[i] << endl;
    }
}


int main()
{
    vector<vector<int>> graph{
        {1, 2},
        {0, 3, 6},
        {0, 3},
        {1, 2, 4, 5, 6},
        {3, 7},
        {3, 7},
        {1, 3, 7},
        {4, 5, 6, 8},
        {7}
    };

    bfs(graph, 6); // O(n*(n + m))
}