#pragma once
#include "Graph.hpp"
#include <stdexcept>

namespace graph {

    /**
     * @brief Checks whether the given graph is empty (has no vertices).
     * 
     * @param g The graph to check.
     * @throws std::invalid_argument if the graph is empty.
     */
    inline void checkGraphNotEmpty(const Graph& g) {
        if (g.getNumOfVertices() == 0) {
            throw std::invalid_argument("Graph is empty");
        }
    }

    /**
     * @brief Validates that the given vertex index is within bounds of the graph.
     * 
     * @param g The graph.
     * @param vertex The vertex index to validate.
     * @throws std::out_of_range if the vertex index is invalid.
     */
    inline void checkValidVertex(const Graph& g, int vertex) {
        int n = g.getNumOfVertices();
        if (vertex < 0 || vertex >= n) {
            throw std::out_of_range("Vertex is out of range");
        }
    }

}