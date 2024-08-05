#include<iostream>
#include<vector>
#include<map>

using namespace std;

void dfs(const vector<vector<int>>& graph,
            map<pair<int, int>, int>& edges,
            vector<int>& cycle,
            int current_vertex)
{
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        int adjacent_vertex = graph[current_vertex][i];
        int a = current_vertex;
        int b = adjacent_vertex;
        if (a > b)
            swap(a, b);
        if (edges[{a, b}] != 0)
        {
            edges[{a, b}]--;
            dfs(graph, edges, cycle, adjacent_vertex);
        }
    }
    cycle.push_back(current_vertex);
}


int main()
{
    vector<vector<int>> graph{
        {1, 3, 4},
        {0, 2, 3, 4},
        {1, 3},
        {0, 1, 2, 4},
        {0, 1, 3},
    };

    vector<int> odd_vertices;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[i].size() % 2 == 1)
        {
            odd_vertices.push_back(i);
        }
    }
    if (odd_vertices.size() > 2)
    {
        std::cout << "No Eulerian cycle and path" << std::endl;
        return 0;
    }
    else if (odd_vertices.size() == 2)
    {
        graph[odd_vertices[0]].push_back(odd_vertices[1]);
        graph[odd_vertices[1]].push_back(odd_vertices[0]);
    }

    vector<int> cycle;
    map<pair<int, int>, int> edges;
    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            if (i < graph[i][j])
            {
                edges[{i, graph[i][j]}]++;
            }
        }
    }

    dfs(graph, edges, cycle, 0);


    if (odd_vertices.size() == 2)
    {
        for (int i = 1; i < cycle.size(); ++i)
        {
            if ((cycle[i - 1] == odd_vertices[0] && cycle[i] == odd_vertices[1]) ||
                (cycle[i - 1] == odd_vertices[1] && cycle[i] == odd_vertices[0]))
            {
                vector<int> new_cycle;
                for (int j = i; j < i + cycle.size(); ++j)
                {
                    int index = j % cycle.size();
                    if (index == 0)
                        continue;
                    new_cycle.push_back(cycle[index]);
                }
                cycle = new_cycle;
            }
        }

    }

    for (int i = 0; i < cycle.size(); ++i)
    {
        std::cout << cycle[i] + 1 << " ";
    }


}