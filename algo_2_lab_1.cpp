#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

class Graph 
{
private:
    vector<vector<int>> adjacencyList;
public:
    void addVertex() 
    {
        adjacencyList.push_back(vector<int>());
    }

    void addEdge(int u, int v) 
    {
        if (u < adjacencyList.size() && v < adjacencyList.size()) 
        {
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }
        else 
        {
            cout << "Invalid vertex index." << endl;
        }
    }

    void printGraph() {
        for (int i = 0; i < adjacencyList.size(); i++) 
        {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjacencyList[i].size(); j++) 
            {
                cout << adjacencyList[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<int> DFS(int startVertex) 
    {
        vector<int> visited(adjacencyList.size(), 0);
        vector<int> result;

        DFSUtil(startVertex, visited, result);

        return result;
    }

    void DFSUtil(int vertex, vector<int>& visited, vector<int>& result) 
    {
        visited[vertex] = 1;
        result.push_back(vertex);

        for (int i = 0; i < adjacencyList[vertex].size(); i++) 
        {
            int neighbor = adjacencyList[vertex][i];
            if (visited[neighbor] == 0) 
            {
                DFSUtil(neighbor, visited, result);
            }
        }
    }

    vector<int> BFS(int startVertex) 
    {
        vector<int> visited(adjacencyList.size(), 0);
        vector<int> result;
        queue<int> q;

        visited[startVertex] = 1;
        q.push(startVertex);

        while (!q.empty()) 
        {
            int vertex = q.front();
            q.pop();
            result.push_back(vertex);

            for (int i = 0; i < adjacencyList[vertex].size(); i++) 
            {
                int neighbor = adjacencyList[vertex][i];
                if (visited[neighbor] == 0) 
                {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }

    vector<int> findVerticesWithLength(int startVertex, int length) 
    {
        vector<int> visited(adjacencyList.size(), 0);
        vector<int> result;

        findVerticesWithLengthUtil(startVertex, length, visited, result);

        return result;
    }

    void findVerticesWithLengthUtil(int vertex, int length, vector<int>& visited, vector<int>& result) 
    {
        visited[vertex] = 1;

        if (length == 0) {
            result.push_back(vertex);
            return;
        }

        for (int i = 0; i < adjacencyList[vertex].size(); i++) 
        {
            int neighbor = adjacencyList[vertex][i];
            if (visited[neighbor] == 0) 
            {
                findVerticesWithLengthUtil(neighbor, length - 1, visited, result);
            }
        }

        visited[vertex] = 0;
    }
};

int main() 
{
    Graph graph;

    // Чтение графа из файла
    ifstream inputFile("graph.txt");
    if (!inputFile.is_open()) 
    {
        cout << "Error opening the file." << endl;
        return 1;
    }

    int numVertices;
    inputFile >> numVertices;

    for (int i = 0; i < numVertices; i++) 
    {
        graph.addVertex();
    }

    int u, v;
    while (inputFile >> u >> v) 
    {
        graph.addEdge(u, v);
    }

    inputFile.close();

    // Вывод графа на экран
    graph.printGraph();
    int startVertex;
    cout << "Enter the start vertex for DFS: ";
    cin >> startVertex;
    //Поиск в глубину
    vector<int> dfsResult = graph.DFS(startVertex);
    cout << "DFS traversal: ";
    for (int i = 0; i < dfsResult.size(); i++) 
    {
        cout << dfsResult[i] << " ";
    }
    cout << endl;

    cout << "Enter the start vertex for BFS: ";
    cin >> startVertex;
    //Поиск в ширину
    vector<int> bfsResult = graph.BFS(startVertex);
    cout << "BFS traversal: ";
    for (int i = 0; i < bfsResult.size(); i++) 
    {
        cout << bfsResult[i] << " ";
    }
    cout << endl;

    // Поиск вершин с заданной длиной пути от стартовой вершины
    int pathLength;
    cout << "Enter the start vertex for task: ";
    cin >> startVertex;
    cout << "Enter the path length: ";
    cin >> pathLength;

    vector<int> result = graph.findVerticesWithLength(startVertex, pathLength);

    cout << "Vertices with path length " << pathLength << " from vertex " << startVertex << ": ";
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
