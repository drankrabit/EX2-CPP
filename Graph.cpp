// ID: 326538022
// Email: itay.alexandrov@gmail.com

#include "Graph.hpp"
#include <stdexcept>

namespace ariel {

// Constructor implementation
Graph::Graph(std::vector<std::vector<int>> &matrix) {
    loadGraph(matrix);
}

// Method to load graph implementation
void Graph::loadGraph(std::vector<std::vector<int>> &matrix) {
    // Check if the matrix is square
    if (matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    V = matrix.size();
    adjacencyMatrix = matrix;
}

// Method to print the adjacency matrix of the graph
void Graph::printGraph() {
    std::cout << "Adjacency Matrix of the graph:\n";
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Helper function to access adjacency matrix
const std::vector<std::vector<int>>& getAdjacencyMatrix(const Graph& graph) {
    return graph.getAdjacencyMatrix();
}

// Function to convert adjacency matrix to string
    std::string adjacencyMatrixToString(const Graph& graph) {
        std::ostringstream result;

        // Iterate through each row of the adjacency matrix
        for (size_t i = 0; i < graph.getAdjacencyMatrix().size(); ++i) {
            result << "[";

            // Convert each element of the row to string and append to result
            for (size_t j = 0; j < graph.getAdjacencyMatrix()[i].size(); ++j) {
                result << graph.getAdjacencyMatrix()[i][j];
                if (j < graph.getAdjacencyMatrix()[i].size() - 1) {
                    result << ", ";
                }
            }
            result << "]";
            // Add a new line after each row
            if (i < graph.getAdjacencyMatrix().size() - 1) {
                result << "\n";
            }
        }
        return result.str();
    }

// Overload operator<<
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    const auto& matrix = getAdjacencyMatrix(graph);
    os << "Adjacency Matrix of the graph:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            os << val << " ";
        }
        os << "\n";
    }
    return os;
}

// Overload operator+
Graph operator+(const Graph& lhs, const Graph& rhs) {
    const auto& lhsMatrix = getAdjacencyMatrix(lhs);
    const auto& rhsMatrix = getAdjacencyMatrix(rhs);

    if (lhsMatrix.size() != rhsMatrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size to add.");
    }

    std::vector<std::vector<int>> resultMatrix(lhsMatrix.size(), std::vector<int>(lhsMatrix.size(), 0));
    for (size_t i = 0; i < lhsMatrix.size(); ++i) {
        for (size_t j = 0; j < lhsMatrix[i].size(); ++j) {
            resultMatrix[i][j] = lhsMatrix[i][j] + rhsMatrix[i][j];
        }
    }

    return Graph(resultMatrix);
}

// Overload operator+=
Graph& operator+=(Graph& lhs, const Graph& rhs) {
    lhs = lhs + rhs;
    return lhs;
}

// Overload unary +
Graph Graph::operator+() const {
    return *this;
}

// Overload operator-
Graph operator-(const Graph& lhs, const Graph& rhs) {
    const auto& lhsMatrix = getAdjacencyMatrix(lhs);
    const auto& rhsMatrix = getAdjacencyMatrix(rhs);

    if (lhsMatrix.size() != rhsMatrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size to subtract.");
    }

    std::vector<std::vector<int>> resultMatrix(lhsMatrix.size(), std::vector<int>(lhsMatrix.size(), 0));
    for (size_t i = 0; i < lhsMatrix.size(); ++i) {
        for (size_t j = 0; j < lhsMatrix[i].size(); ++j) {
            resultMatrix[i][j] = lhsMatrix[i][j] - rhsMatrix[i][j];
        }
    }

    return Graph(resultMatrix);
}

// Overload operator-=
Graph& operator-=(Graph& lhs, const Graph& rhs) {
    lhs = lhs - rhs;
    return lhs;
}

// Overload unary -
Graph operator-(const Graph& g) {
    const auto& matrix = getAdjacencyMatrix(g);
    std::vector<std::vector<int>> resultMatrix(matrix.size(), std::vector<int>(matrix.size(), 0));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            resultMatrix[i][j] = -matrix[i][j];
        }
    }
    return Graph(resultMatrix);
}

// Overload operator==
bool operator==(const Graph& lhs, const Graph& rhs) {
    return lhs.V == rhs.V && lhs.adjacencyMatrix == rhs.adjacencyMatrix;
}

// Overload operator!=
bool operator!=(const Graph& lhs, const Graph& rhs) {
    return !(lhs == rhs);
}

// Overload operator<
bool operator<(const Graph& lhs, const Graph& rhs) {
    if (lhs == rhs) {
        return false;
    }
    if (lhs.V != rhs.V) {
        return lhs.V < rhs.V;
    }
    int lhsEdges = countEdges(lhs.adjacencyMatrix);
    int rhsEdges = countEdges(rhs.adjacencyMatrix);
    return lhsEdges < rhsEdges;
}

// Overload operator<=
bool operator<=(const Graph& lhs, const Graph& rhs) {
    return lhs < rhs || lhs == rhs;
}

// Overload operator>
bool operator>(const Graph& lhs, const Graph& rhs) {
    return !(lhs <= rhs);
}

// Overload operator>=
bool operator>=(const Graph& lhs, const Graph& rhs) {
    return !(lhs < rhs);
}

// Overload pre-increment operator++
Graph& Graph::operator++() {
    for (auto& row : adjacencyMatrix) {
        for (auto& val : row) {
            ++val;
        }
    }
    return *this;
}

// Overload post-increment operator++
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

// Overload pre-decrement operator--
Graph& Graph::operator--() {
    for (auto& row : adjacencyMatrix) {
        for (auto& val : row) {
            --val;
        }
    }
    return *this;
}

// Overload post-decrement operator--
Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

// Overload scalar multiplication operator*
Graph& operator*=(Graph& g, int scalar) {
    for (size_t i = 0; i < g.V; ++i) {
        for (size_t j = 0; j < g.V; ++j) {
            g.adjacencyMatrix[i][j] *= scalar;
        }
    }
    return g;
}


Graph& operator*=(int scalar, Graph& g) {
    return g *= scalar;
}

// Overload scalar division operator/=
Graph& operator/=(Graph& graph, int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    for (auto& row : graph.adjacencyMatrix) {
        for (auto& val : row) {
            val /= scalar;
        }
    }
    return graph;
}

Graph& operator/=(int scalar, Graph& graph) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    return graph /= scalar;
}

// Overload graph multiplication operator*
Graph operator*(const Graph& lhs, const Graph& rhs) {
    if (lhs.V != rhs.V) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }
    std::vector<std::vector<int>> resultMatrix(lhs.V, std::vector<int>(lhs.V, 0));
    for (size_t i = 0; i < lhs.V; ++i) {
        for (size_t j = 0; j < lhs.V; ++j) {
            for (size_t k = 0; k < lhs.V; ++k) {
                resultMatrix[i][j] += lhs.adjacencyMatrix[i][k] * rhs.adjacencyMatrix[k][j];
            }
        }
    }
    return Graph(resultMatrix);
}

// Helper function to count edges
int countEdges(const std::vector<std::vector<int>>& adjacencyMatrix) {
    int edges = 0;
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            if (val != 0) {
                edges++;
            }
        }
    }
    return edges;
}


} // namespace ariel