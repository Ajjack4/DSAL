#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Struct to represent a city or airport
struct City {
    string name;
    City(string n) : name(n) {}
};

// Struct to represent an edge between two cities
struct Flight {
    int cost; // Cost of the flight (time or fuel)
    City* destination; // Destination city
    Flight(int c, City* dest) : cost(c), destination(dest) {}
};

// Graph class to represent the graph using an adjacency list
class Graph {
private:
    unordered_map<City*, vector<Flight>> adjacencyList;

public:
    // Function to add an edge between two cities
    void addEdge(City* src, City* dest, int cost) {
        adjacencyList[src].push_back(Flight(cost, dest));
        // For undirected graph, add the reverse edge as well
        adjacencyList[dest].push_back(Flight(cost, src));
    }

    // Function to check if the graph is connected
    bool isConnected() {
        unordered_map<City*, bool> visited;
        queue<City*> q;

        // Start BFS from any city
        City* start = adjacencyList.begin()->first;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            City* current = q.front();
            q.pop();

            for (Flight& flight : adjacencyList[current]) {
                if (!visited[flight.destination]) {
                    visited[flight.destination] = true;
                    q.push(flight.destination);
                }
            }
        }

        // Check if all cities are visited
        for (auto& pair : adjacencyList) {
            if (!visited[pair.first]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Create cities
    City* cityA = new City("City A");
    City* cityB = new City("City B");
    City* cityC = new City("City C");
    City* cityD = new City("City D");

    // Create graph
    Graph graph;
    graph.addEdge(cityA, cityB, 1); // Time or fuel cost from A to B
    graph.addEdge(cityB, cityC, 2); // Time or fuel cost from B to C
    graph.addEdge(cityC, cityD, 3); // Time or fuel cost from C to D

    // Check if the graph is connected
    if (graph.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}

