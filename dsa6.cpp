#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

// Struct to represent a landmark
struct Landmark {
    string name;
    Landmark(string n) : name(n) {}
};

// Graph class to represent the graph using an adjacency list
class Graph {
private:
    unordered_map<Landmark*, vector<Landmark*>> adjacencyList;

public:
    // Function to add an edge between two landmarks
    void addEdge(Landmark* src, Landmark* dest) {
        adjacencyList[src].push_back(dest);
        // For undirected graph, add the reverse edge as well
        adjacencyList[dest].push_back(src);
    }

    // Depth-First Search (DFS)
    void DFS(Landmark* start) {
        unordered_map<Landmark*, bool> visited;
        stack<Landmark*> stack;

        stack.push(start);

        while (!stack.empty()) {
            Landmark* current = stack.top();
            stack.pop();

            if (!visited[current]) {
                cout << current->name << " ";
                visited[current] = true;

                for (Landmark* neighbor : adjacencyList[current]) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }

    // Breadth-First Search (BFS)
    void BFS(Landmark* start) {
        unordered_map<Landmark*, bool> visited;
        queue<Landmark*> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            Landmark* current = q.front();
            q.pop();

            cout << current->name << " ";

            for (Landmark* neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // Create landmarks
    Landmark* a = new Landmark("A");
    Landmark* b = new Landmark("B");
    Landmark* c = new Landmark("C");
    Landmark* d = new Landmark("D");
    Landmark* e = new Landmark("E");

    // Create graph
    Graph graph;
    graph.addEdge(a, b);
    graph.addEdge(b, c);
    graph.addEdge(b, d);
    graph.addEdge(c, e);
    graph.addEdge(d, e);

    // Perform DFS from landmark A
    cout << "DFS: ";
    graph.DFS(a);
    cout << endl;

    // Perform BFS from landmark A
    cout << "BFS: ";
    graph.BFS(a);
    cout << endl;

    return 0;
}

