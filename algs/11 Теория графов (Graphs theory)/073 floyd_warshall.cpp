#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start_vertex)
{

    const int Inf = 1000000;
    vector<int> dist(graph.size(), Inf);
    dist[start_vertex] = 0;
    set<pair<int, int>> s;
    s.insert({ 0, start_vertex });

    while (!s.empty()) // O(m * log(n))
    {
        int current_vertex = s.begin()->second;
        s.erase(s.begin());

        for (int i = 0; i < graph[current_vertex].size(); ++i)
        {
            int adjacent_vertex = graph[current_vertex][i].first;
            int weight = graph[current_vertex][i].second;

            if (dist[current_vertex] + weight < dist[adjacent_vertex])
            {
                s.erase({ dist[adjacent_vertex], adjacent_vertex });
                dist[adjacent_vertex] = dist[current_vertex] + weight;
                s.insert({ dist[adjacent_vertex], adjacent_vertex });
            }
        }
    }
    return dist;
}


vector<vector<int>> floyd_warshall(vector<vector<int>> dist)
{
    const int n = dist.size();
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

int main()
{
    vector<vector<pair<int, int>>> graph{
        {{1, 10}, {5, 5}},
        {{0, 10}, {2, 1}},
        {{1, 1}, {3, 5}, {5, 7}, {6, 10}},
        {{2, 5}, {4, 1}},
        {{3, 1}, {6, 2}},
        {{0, 5}, {2, 7}, {6, 100}, {7, 3}},
        {{2, 10}, {4, 2}, {5, 100}, {7, 8}, {8, 100}},
        {{5, 3}, {6, 8}, {9, 1}},
        {{6, 100}, {9, 1}},
        {{7, 1}, {8, 1}},
    };

    const int Inf = 1e9 + 7;
    vector<vector<int>> graph2(graph.size(), vector<int>(graph.size(), Inf));

    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            graph2[i][graph[i][j].first] = graph[i][j].second;
            graph2[graph[i][j].first][i] = graph[i][j].second;
        }
    }



    for(int i = 0; i < graph.size(); ++i)
    {
        vector<int> dist = dijkstra(graph, i);
        for (int i = 0; i < dist.size(); ++i)
        {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    auto dist = floyd_warshall(graph2);
    for (int i = 0; i < dist.size(); ++i)
    {
        for (int j = 0; j < dist[i].size(); ++j)
        {
            if (i == j)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}