#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Graph class
class Graph {
private:
    int vertices;                    
    vector<vector<int>> adjList;     // Adjacency list

public:
    // Constructor
    Graph(int v) : vertices(v), adjList(v) {}

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // DFS helper function
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS traversal
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // BFS traversal
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    int vertices = 6; // Number of vertices
    Graph g(vertices);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform DFS and BFS
    g.DFS(0);
    g.BFS(0);

    return 0;
}
