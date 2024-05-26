// ID: 326538022
// Email: itay.alexandrov@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <sstream>

namespace ariel {

// Forward declaration of countEdges function
int countEdges(const std::vector<std::vector<int>>& adjacencyMatrix);

class Graph {
private:
    size_t V; // Number of vertices
protected:
    std::vector<std::vector<int>> adjacencyMatrix; // Adjacency matrix representation of the graph
public:
    // Default constructor
    Graph() : V(0), adjacencyMatrix(std::vector<std::vector<int>>()) {}

    // Constructor that initializes the graph with a given adjacency matrix
    Graph(std::vector<std::vector<int>> &matrix);

    // Method to load a graph with a given adjacency matrix
    void loadGraph(std::vector<std::vector<int>> &matrix);

    // Method to print the adjacency matrix of the graph
    void printGraph();

    // Getter method to return the number of vertices
    size_t getV() const { return V; }

    // Getter method to return the adjacency matrix
    const std::vector<std::vector<int>>& getAdjacencyMatrix() const { return adjacencyMatrix; }

    // Function to convert adjacency matrix to string
    std::string adjacencyMatrixToString();

    // Arithmetic operators
    friend Graph operator+(const Graph& lhs, const Graph& rhs);
    friend Graph& operator+=(Graph& lhs, const Graph& rhs);
    friend Graph operator-(const Graph& lhs, const Graph& rhs);
    friend Graph& operator-=(Graph& lhs, const Graph& rhs);

    // Unary operators
    Graph operator+() const;
    friend Graph operator-(const Graph& g);

    // Comparison operators
    friend bool operator==(const Graph& lhs, const Graph& rhs);
    friend bool operator!=(const Graph& lhs, const Graph& rhs);
    friend bool operator<(const Graph& lhs, const Graph& rhs);
    friend bool operator<=(const Graph& lhs, const Graph& rhs);
    friend bool operator>(const Graph& lhs, const Graph& rhs);
    friend bool operator>=(const Graph& lhs, const Graph& rhs);

    // Increment and decrement operators
    Graph& operator++();    // Prefix increment
    Graph operator++(int);  // Postfix increment
    Graph& operator--();    // Prefix decrement
    Graph operator--(int);  // Postfix decrement

    // Scalar multiplication
    friend Graph& operator*=(Graph& g, int scalar);
    friend Graph& operator*=(int scalar, const Graph& g);

    // scalar division
    friend Graph& operator/=(Graph& graph, int scalar);
    friend Graph& operator/=(int scalar, const Graph& g);

    // Graph multiplication
    friend Graph operator*(const Graph& lhs, const Graph& rhs);

    // Output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

} // namespace ariel

#endif // GRAPH_HPP