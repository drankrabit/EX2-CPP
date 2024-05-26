Graphs Library

Description:
-------------------------
This library provides a comprehensive implementation of graph operations and algorithms using a Graph class that represents graphs through an adjacency matrix. It includes various functionalities such as arithmetic operations on graphs, comparison of graphs, scalar operations, and edge counting.

Implementation:
-------------------------
1. Graph Class (Graph.hpp, Graph.cpp)
    - The Graph class represents a graph using an adjacency matrix, stored as a 2D vector.
    - The class provides a range of methods and operator overloads to perform various operations on graphs.

Graph Construction and Loading:
-------------------------------------
   1. Constructor: Constructs a graph using a given adjacency matrix.
        - Parameters: std::vector<std::vector<int>> &matrix - The adjacency matrix representing the graph.
        - Throws: std::invalid_argument if the matrix is not square.

   2. loadGraph: Loads a graph with a given adjacency matrix and ensures it is a square matrix.
        - Parameters: std::vector<std::vector<int>> &matrix - The adjacency matrix representing the graph.
        - Throws: std::invalid_argument if the matrix is not square.
        - Details: This method first checks if the matrix is square (i.e., the number of rows equals the number of columns). If the check passes, it sets the adjacency matrix and the number of vertices.
     
Functions:
-------------------------
Graph Representation:
-------------------------
1. printGraph: Prints the adjacency matrix of the graph.
    - Details: This method iterates through each row of the adjacency matrix and prints each element, formatting the output as a matrix.

2. getAdjacencyMatrix: Returns the adjacency matrix of the graph.
    - Returns: const std::vector<std::vector<int>>& - A reference to the adjacency matrix.
    - Details: This method provides read-only access to the adjacency matrix.

3. adjacencyMatrixToString: Converts the adjacency matrix to a string format for easy viewing.
    - Parameters: const Graph& graph - The graph whose adjacency matrix is to be converted.
    - Returns: std::string - The string representation of the adjacency matrix.
    - Details: This method iterates through each row and element of the adjacency matrix, formats them into a string with appropriate delimiters and line breaks.

Operator Overloads:
-------------------------
1. Output Stream (operator<<): Prints the adjacency matrix.
    - Parameters: std::ostream& os, const Graph& graph
    - Returns: std::ostream&
    - Details: This operator overload allows the graph's adjacency matrix to be printed directly using std::cout or other output streams.

2. Addition (operator+): Adds two graphs element-wise.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: Graph
    - Throws: std::invalid_argument if graphs are not of the same size.
    - Details: This operator creates a new graph where each element is the sum of the corresponding elements from the two input graphs' adjacency matrices.

3. Addition Assignment (operator+=): Adds and assigns the result to the left-hand graph.
    - Parameters: Graph& lhs, const Graph& rhs
    - Returns: Graph&
    - Throws: std::invalid_argument if graphs are not of the same size.
    - Details: This operator adds the right-hand graph to the left-hand graph, updating the left-hand graph's adjacency matrix.

4. Subtraction (operator-): Subtracts two graphs element-wise.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: Graph
    - Throws: std::invalid_argument if graphs are not of the same size.
    - Details: This operator creates a new graph where each element is the difference of the corresponding elements from the two input graphs' adjacency matrices.

5. Subtraction Assignment (operator-=): Subtracts and assigns the result to the left-hand graph.
    - Parameters: Graph& lhs, const Graph& rhs
    - Returns: Graph&
    - Throws: std::invalid_argument if graphs are not of the same size.
    - Details: This operator subtracts the right-hand graph from the left-hand graph, updating the left-hand graph's adjacency matrix.

6. Unary Plus (operator+): Returns a copy of the graph.
    - Returns: Graph
    - Details: This operator returns a new graph that is a copy of the original graph.

7. Unary Minus (operator-): Negates all elements of the adjacency matrix.
    - Returns: Graph
    - Details: This operator creates a new graph where each element is the negation of the corresponding element from the original graph's adjacency matrix.

8. Equality (operator==): Checks if two graphs are identical.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: bool
    - Details: This operator compares the adjacency matrices and the number of vertices of two graphs to determine if they are identical.

9. Inequality (operator!=): Checks if two graphs are not identical.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: bool
    - Details: This operator returns the negation of the equality operator.
10. Less Than (operator<): Compares two graphs based on vertex count and number of edges.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: bool
    - Details: This operator first compares the number of vertices. If equal, it compares the number of edges in each graph.

11. Less Than or Equal (operator<=): Checks if one graph is less than or equal to another.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: bool
    - Details: This operator returns true if the left-hand graph is less than or equal to the right-hand graph.

12. Greater Than (operator>): Checks if one graph is greater than another.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: bool
    - Details: This operator returns true if the left-hand graph is greater than the right-hand graph.

13. Greater Than or Equal (operator>=): Checks if one graph is greater than or equal to another.
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: bool
    - Details: This operator returns true if the left-hand graph is greater than or equal to the right-hand graph.

14. Pre-increment (operator++): Increments all elements of the adjacency matrix by one.
    - Returns: Graph&
    - Details: This operator increments each element of the adjacency matrix by one and returns the modified graph.

15. Post-increment (operator++(int)): Increments all elements of the adjacency matrix by one and returns the original graph.
    - Returns: Graph
    - Details: This operator creates a copy of the original graph, increments each element of the adjacency matrix by one, and returns the original graph.

16. Pre-decrement (operator--): Decrements all elements of the adjacency matrix by one.
    - Returns: Graph&
    - Details: This operator decrements each element of the adjacency matrix by one and returns the modified graph.

17. Post-decrement (operator--(int)): Decrements all elements of the adjacency matrix by one and returns the original graph.
    - Returns: Graph
    - Details: This operator creates a copy of the original graph, decrements each element of the adjacency matrix by one, and returns the original graph.

18. Scalar Multiplication (operator*=)
    - Parameters: Graph& g, int scalar
    - Returns: Graph&
    - Details: This operator multiplies each element of the adjacency matrix by the scalar value.

19. Scalar Division (operator/=)
    - Parameters: Graph& graph, int scalar
    - Returns: Graph&
    - Throws: std::invalid_argument if scalar is zero.
    - Details: This operator divides each element of the adjacency matrix by the scalar value.

20. Graph Multiplication (operator*)
    - Parameters: const Graph& lhs, const Graph& rhs
    - Returns: Graph
    - Throws: std::invalid_argument if the number of columns in lhs does not match the number of rows in rhs.
    - Details: This operator performs matrix multiplication on the adjacency matrices of the two graphs and returns a new graph.

Helper Functions:
-------------------------
1. countEdges
    - Parameters: const std::vector<std::vector<int>>& adjacencyMatrix
    - Returns: int
    - Details: This function counts the number of non-zero elements in the adjacency matrix, representing the number of edges in the graph. It iterates through each element of the adjacency matrix and increments the edge count for non-zero elements.

Division of Code:
-------------------------
Graph Class:
    Graph.hpp: Header file containing the declaration of the Graph class.
    Graph.cpp: Source file containing the implementation of the Graph class.
