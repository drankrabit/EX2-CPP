// ID: 326538022
// Email: itay.alexandrov@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string> 

namespace ariel {

class Algorithms {
public:
    // Method to check if the graph is connected
    static bool isConnected(const Graph &g);

    // Method to find the shortest path between two vertices
    static std::string shortestPath(const Graph &g, int start, int end);

    // Method to check if the graph contains a cycle
    static std::string isContainsCycle(const Graph &g); 

    // Method to check if the graph is bipartite
    static std::string isBipartite(const Graph &g);

    // Method to check if the graph contains a negative weight cycle
    static bool negativeCycle(const Graph &g);
};

} // namespace ariel

#endif // ALGORITHMS_HPP
