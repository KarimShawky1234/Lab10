#ifndef DUG_H
#define DUG_H

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct Edge {
    int source;
    int destination;
};

class DirectedUnweightedGraph {
private:
    int numberOfVertices;
    vector<vector<int>> adjacencyList;
    void DFSRec(int vertex, vector<bool>& visited);

public:
    DirectedUnweightedGraph(int count);
    void addEdge(Edge edge);
    void BFS(int startVertex); // Breadth First Search
    void DFS(int startVertex); // Depth First Search
};

DirectedUnweightedGraph::DirectedUnweightedGraph(int count) : numberOfVertices(count) {
    adjacencyList.resize(numberOfVertices);
}

void DirectedUnweightedGraph::addEdge(Edge edge) {
    int src = edge.source;
    int dest = edge.destination;

    if (src >= 0 && src < numberOfVertices && dest >= 0 && dest < numberOfVertices) {
        adjacencyList[src].push_back(dest);
    } else {
        cout << "Invalid edge: (" << src << ", " << dest << ")" << endl;
    }
}

void DirectedUnweightedGraph::BFS(int startVertex) {
    vector<bool> visited(numberOfVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        cout << currentVertex << " ";

        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void DirectedUnweightedGraph::DFSRec(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            DFSRec(neighbor, visited);
        }
    }
}

void DirectedUnweightedGraph::DFS(int startVertex) {
    vector<bool> visited(numberOfVertices, false);
    DFSRec(startVertex, visited);
}


#endif
