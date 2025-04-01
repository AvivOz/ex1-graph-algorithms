#pragma once
#include "Graph.hpp"

namespace graph {

    class Algorithms {

        public:

            /**
             * Performs Breadth-First Search (BFS) starting from the given source vertex.
             * Returns a graph representing the BFS tree, which contains only the tree edges
             * discovered during the traversal.
             *
             * @param g The input graph.
             * @param sourceVertex The vertex from which BFS starts.
             * @return A graph representing the BFS traversal tree.
             * @throws std::out_of_range if the source vertex is invalid.
             */
            static Graph bfs(const Graph& g, int sourceVertex);

            /**
             * Performs Depth-First Search (DFS) starting from the given source vertex.
             * Returns a graph representing the DFS tree (or forest), containing only
             * the tree edges encountered during the traversal.
             *
             * @param g The input graph.
             * @param sourceVertex The vertex from which DFS starts.
             * @return A graph representing the DFS traversal tree.
             * @throws std::out_of_range if the source vertex is invalid.
             */
            static Graph dfs(const Graph& g, int sourceVertex);
    };
}