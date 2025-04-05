// Author: avivoz4@gmail.com

#pragma once
#include "graph.hpp"

namespace graph {

    class Algorithms {

    public:

        /**
         * @brief Performs Breadth-First Search (BFS) starting from the given source vertex.
         * 
         * @param g The input graph.
         * @param sourceVertex The vertex from which BFS starts.
         * @return A graph representing the BFS traversal tree (only tree edges).
         * @throws std::invalid_argument if the graph is empty.
         * @throws std::out_of_range if the source vertex is invalid.
         */
        static Graph bfs(const Graph& g, int sourceVertex);

        /**
         * @brief Performs Depth-First Search (DFS) starting from the given source vertex.
         * 
         * @param g The input graph.
         * @param sourceVertex The vertex from which DFS starts.
         * @return A graph representing the DFS traversal tree (only tree edges).
         * @throws std::invalid_argument if the graph is empty.
         * @throws std::out_of_range if the source vertex is invalid.
         */
        static Graph dfs(const Graph& g, int sourceVertex);

        /**
         * @brief Computes the shortest-path tree from a source vertex using Dijkstra's algorithm.
         * 
         * @param g The input graph (assumes non-negative weights).
         * @param sourceVertex The vertex from which paths are calculated.
         * @return A graph containing only the edges that are part of the shortest paths.
         * @throws std::invalid_argument if the graph is empty.
         * @throws std::out_of_range if the source vertex is invalid.
         */
        static Graph dijkstra(const Graph& g, int sourceVertex);

        /**
         * @brief Computes a Minimum Spanning Tree (MST) of the graph using Prim's algorithm.
         * 
         * @param g The input graph (must be connected and undirected).
         * @return A graph containing the MST edges.
         * @throws std::invalid_argument if the graph is empty.
         */
        static Graph prim(const Graph& g);

        /**
         * @brief Computes a Minimum Spanning Tree (MST) of the graph using Kruskal's algorithm.
         * 
         * @param g The input graph (must be connected and undirected).
         * @return A graph containing the MST edges.
         * @throws std::invalid_argument if the graph is empty.
         */
        static Graph kruskal(const Graph& g);
    };
}
