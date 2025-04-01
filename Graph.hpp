#pragma once
#include "List.hpp"

namespace graph {

    // Represents an edge in the graph (used in adjacency lists)
    struct Edge {
        int dest; // Destination vertex
        int weight; // Weight of the edge

        // Equality operator – compares only by destination
        // Used for removing edges from the adjacency list
        bool operator==(const Edge& other) const {
            return dest == other.dest;
        }
    };

    // Output stream operator to print Edge objects in the format: (dest, weight)
    inline std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "(" << edge.dest << ", " << edge.weight << ")";
        return os;
    }

    class Graph {
    private:
        int numOfVertices; // Number of vertices initialized in the graph (fixed after creation)
        List<Edge>* adjacencyList; // Array of adjacency lists: adjacencyList[i] holds all edges from vertex i
    public:

        /**
        * Constructs a graph with the given number of vertices.
        * The graph is initially empty (no edges).
        */
        Graph(int n);

        /**
        * Destructor – frees the dynamically allocated adjacency list array.
        */
        ~Graph(); 

        /**
        * Adds an undirected edge between source and destination vertices,
        * with optional weight (default is 1).
        * @param sourceVertex Index of the source vertex.
        * @param destinationVertex Index of the destination vertex.
        * @param weight Weight of the edge (default is 1).
        * @throws std::out_of_range if either vertex index is invalid.
        */
        void addEdge(int sourceVertex, int destinationVertex, int weight = 1); 

        /**
        * Removes an undirected edge between source and destination.
        * @param sourceVertex Index of the source vertex.
        * @param destinationVertex Index of the destination vertex.
        * @throws std::out_of_range if either vertex index is invalid.
        * @throws std::runtime_error if the edge does not exist.
        */
        void removeEdge(int sourceVertex, int destinationVertex); 

         /**
        * Prints the adjacency list representation of the graph.
        */
        void print_graph() const; 

        /**
        * Returns the number of vertices in the graph.
        */
        int getNumOfVertices() const {return numOfVertices;} 
        
        /**
        * Returns a const reference to the adjacency list of a specific vertex.
        * @param vertex Index of the vertex (must be in range [0, numOfVertices-1])
        * @return A const reference to the list of outgoing edges.
        * @throws std::out_of_range if the vertex index is invalid.
        */
        const List<Edge>& getAdjacency(int vertex) const; 
    };

}