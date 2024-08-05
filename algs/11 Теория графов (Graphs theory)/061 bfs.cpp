#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs_list(const vector<vector<int>>& graph)
{
    int start_vertex = 0;
    vector<int> used(graph.size(), 0);
    used[start_vertex] = 1;
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
            if (!used[adjacent_vertex])
            {
                q.push(adjacent_vertex);
                used[adjacent_vertex] = 1;
            }
        }
    }

}


void bfs_matrix(const vector<vector<int>>& graph)
{
    int start_vertex = 0;
    vector<int> used(graph.size(), 0);
    used[start_vertex] = 1;
    queue<int> q;
    q.push(start_vertex);

    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop();
        std::cout << current_vertex + 1 << " ";
        
        for (int i = 0; i < graph[current_vertex].size(); ++i)
        {
            if (graph[current_vertex][i] == 1)
            {
                int adjacent_vertex = i;
                if (!used[adjacent_vertex])
                {
                    q.push(adjacent_vertex);
                    used[adjacent_vertex] = 1;
                }
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

    bfs_list(adjacency_list);
    cout << endl;
    bfs_matrix(adjacency_matrix);
}