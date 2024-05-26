// ID: 326538022
// Email: itay.alexandrov@gmail.com

#include "Algorithms.hpp"
#include <algorithm>
#include <queue>
#include <iostream>
#include <climits>

namespace ariel {

// Breadth-first search function to check connectivity
bool BFS(const Graph& g, size_t start, bool* visited) {
    std::queue<size_t> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        size_t current = queue.front();
        queue.pop();

        for (size_t i = 0; i < g.getV(); ++i) {
            if (g.getAdjacencyMatrix()[current][i] && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    for (size_t i = 0; i < g.getV(); ++i) {
        if (!visited[i])
            return false;
    }
    return true;
}

// Method to check if the graph is connected
bool Algorithms::isConnected(const Graph& g) {
    bool* visited = new bool[g.getV()];
    for (size_t i = 0; i < g.getV(); ++i)
        visited[i] = false;

    // Start BFS from vertex 0
    bool connected = BFS(g, 0, visited);

    delete[] visited;
    return connected;
}

// Method to find the shortest path between two vertices
std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
    int* dist = new int[g.getV()];
    bool* visited = new bool[g.getV()];
    int* parent = new int[g.getV()];

    // Initialization
    for (int i = 0; i < g.getV(); ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[start] = 0;
    visited[start] = true;

    std::queue<size_t> queue;
    queue.push(static_cast<size_t>(start));

    // BFS traversal
    while (!queue.empty()) {
        size_t u = queue.front();
        queue.pop();

        for (size_t v = 0; v < g.getV(); ++v) {
            if (g.getAdjacencyMatrix()[u][v] && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue.push(v);
            }
        }
    }

    // Constructing the shortest path
    if (dist[end] == INT_MAX) {
        delete[] dist;
        delete[] visited;
        delete[] parent;
        return "No path found!";
    }

    std::string path = std::to_string(end);
    int current = end;
    while (parent[current] != start) {
        path = std::to_string(parent[current]) + "->" + path;
        current = parent[current];
    }
    path = std::to_string(start) + "->" + path;

    delete[] dist;
    delete[] visited;
    delete[] parent;

    return path;
}

// Utility function to check for cycle in the graph
bool isCyclicUtil(const Graph& g, size_t v, bool visited[], int parent, int cycle[]) {
    visited[v] = true;

    for (size_t i = 0; i < g.getV(); ++i) {
        if (g.getAdjacencyMatrix()[v][i] != 0) {
            if (!visited[i]) {
                if (isCyclicUtil(g, i, visited, v, cycle)) {
                    cycle[v] = 1;
                    return true;
                }
            } else if (i != parent || cycle[i] == 1) {
                cycle[v] = 1;
                return true;
            }
        }
    }

    return false;
}

// Method to check if the graph contains a cycle
std::string Algorithms::isContainsCycle(const Graph& g) {
    bool* visited = new bool[g.getV()];
    int* parent = new int[g.getV()];
    int* cycle = new int[g.getV()];

    // Initialization
    for (size_t i = 0; i < g.getV(); ++i) {
        visited[i] = false;
        parent[i] = -1;
        cycle[i] = 0;
    }

    // Checking for cycles in each unvisited vertex
    for (size_t i = 0; i < g.getV(); ++i) {
        if (!visited[i] && isCyclicUtil(g, i, visited, -1, cycle)) {
            // Constructing cycle path
            std::string result = "The cycle is: ";
            for (size_t j = 0; j < g.getV(); ++j) {
                if (cycle[j] == 1) {
                    result += std::to_string(j);
                    result += "->";
                }
            }
            result.pop_back();
            result.pop_back();
            delete[] visited;
            delete[] parent;
            delete[] cycle;
            return result;
        }
    }

    delete[] visited;
    delete[] parent;
    delete[] cycle;

    return "0";
}

// Method to check if the graph is bipartite
std::string Algorithms::isBipartite(const Graph& g) {
    std::vector<int> color(g.getV(), -1); // -1: not colored, 0: color 0, 1: color 1
    std::queue<size_t> q;

    // Coloring vertices and checking bipartiteness
    for (size_t i = 0; i < g.getV(); ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                size_t u = q.front();
                q.pop();

                for (size_t v = 0; v < g.getV(); ++v) {
                    if (g.getAdjacencyMatrix()[u][v] != 0) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return "0";
                        }
                    }
                }
            }
        }
    }

    // Constructing the bipartite sets
    std::vector<std::vector<size_t>> groups(2);
    for (size_t i = 0; i < g.getV(); ++i) {
        groups[static_cast<size_t>(color[i])].push_back(i);
    }

    // Constructing the result string
    std::string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < groups[0].size(); ++i) {
        result += std::to_string(groups[0][i]);
        if (i < groups[0].size() - 1)
            result += ", ";
    }
    result += "}, B={";
    for (size_t i = 0; i < groups[1].size(); ++i) {
        result += std::to_string(groups[1][i]);
        if (i < groups[1].size() - 1)
            result += ", ";
    }
    result += "}.";

    return result;
}

// Method to check if the graph contains a negative weight cycle
bool Algorithms::negativeCycle(const Graph& g) {
    size_t V = g.getV();
    int* dist = new int[V];

    // Initialize distance from source to source as 0
    for (size_t i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;

    // Relax all edges |V| - 1 times.
    for (size_t i = 1; i <= V - 1; i++) {
        for (size_t u = 0; u < V; u++) {
            for (size_t v = 0; v < V; v++) {
                int weight = g.getAdjacencyMatrix()[u][v];
                if (weight && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles.
    for (size_t u = 0; u < V; u++) {
        for (size_t v = 0; v < V; v++) {
            int weight = g.getAdjacencyMatrix()[u][v];
            if (weight && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains negative weight cycle" << std::endl;
                delete[] dist;
                return true;
            }
        }
    }
    std::cout << "Graph doesn't contain negative weight cycle" << std::endl;
    delete[] dist;
    return false;
}

} // namespace ariel
