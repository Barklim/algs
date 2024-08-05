#include<iostream>
#include<vector>

using namespace std;


void list_of_edges()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[i] = { a, b };
    }

    std::cout << "List of edges:\n";
    for (int i = 0; i < m; ++i)
    {
        std::cout << edges[i].first << " " << edges[i].second << std::endl;
    }
    cout << endl;
    cout << endl;
}

void adjacency_matrix()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        // 1 <= a, b <= n
        --a, --b;
        matrix[a][b] = 1;
    }
    std::cout << "Adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void adjacency_list()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        matrix[a].push_back(b);
    }

    std::cout << "Adjacency list:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

}


int main()
{
    /*
    n m
    a_1 b_1
    a_2 b_2
    ...
    a_m b_m
    */
    list_of_edges();
    adjacency_matrix();
    adjacency_list();

/*
5 7
1 2
1 3
1 4
1 5
2 3
3 4
4 5
*/

}