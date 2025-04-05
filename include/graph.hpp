// Author: avivoz4@gmail.com

#pragma once
#include <iostream>
#include "list.hpp"

namespace graph {

    /**
     * @brief Represents an edge in the graph (used in adjacency lists).
     */
    struct Edge {
        int dest;   ///< Destination vertex.
        int weight; ///< Weight of the edge.

        /**
         * @brief Equality operator – compares only by destination.
         * Used for removing edges from the adjacency list.
         */
        bool operator==(const Edge& other) const {
            return dest == other.dest;
        }
    };

    /**
     * @brief Represents a graph using an adjacency list.
     */
    class Graph {
    private:
        int numOfVertices; ///< Number of vertices initialized in the graph (fixed after creation).
        List<Edge>* adjacencyList; ///< Array of adjacency lists: adjacencyList[i] holds all edges from vertex i.

    public:
        /**
         * @brief Constructs a graph with the given number of vertices.
         * 
         * The graph is initially empty (no edges).
         * @param n Number of vertices in the graph.
         */
        Graph(int n);

        /**
         * @brief Destructor – frees the dynamically allocated adjacency list array.
         */
        ~Graph(); 

        /**
         * @brief Adds an edge between source and destination vertices.
         * 
         * If @p directed is false (default), adds an undirected edge.
         * If @p directed is true, adds only a directed edge from source to destination.
         * 
         * @param sourceVertex Index of the source vertex.
         * @param destinationVertex Index of the destination vertex.
         * @param weight Weight of the edge (default is 1).
         * @param directed Whether the edge is directed (default is false).
         * @throws std::out_of_range if either vertex index is invalid.
         */
        void addEdge(int sourceVertex, int destinationVertex, int weight = 1, bool directed = false); 

        /**
         * @brief Removes an undirected edge between source and destination.
         * 
         * @param sourceVertex Index of the source vertex.
         * @param destinationVertex Index of the destination vertex.
         * @throws std::out_of_range if either vertex index is invalid.
         * @throws std::runtime_error if the edge does not exist.
         */
        void removeEdge(int sourceVertex, int destinationVertex); 

        /**
         * @brief Outputs the contents of the graph to an output stream.
         * 
         * Prints the adjacency list of each vertex.
         * 
         * @param os The output stream (e.g., std::cout or std::ostringstream).
         */
        void print_graph(std::ostream& os) const;

        /**
         * @brief Returns the number of vertices in the graph.
         * @return Number of vertices.
         */
        int getNumOfVertices() const { return numOfVertices; } 
        
        /**
         * @brief Returns a const reference to the adjacency list of a specific vertex.
         * 
         * @param vertex Index of the vertex (must be in range [0, numOfVertices-1]).
         * @return A const reference to the list of outgoing edges.
         * @throws std::out_of_range if the vertex index is invalid.
         */
        const List<Edge>& getAdjacency(int vertex) const; 
    };

}