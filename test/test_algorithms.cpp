// Author: avivoz4@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/graph.hpp"
#include "../include/queue.hpp"
#include "../include/priority_queue.hpp"
#include "../include/union_find.hpp"
#include "../include/list.hpp"
#include "../include/algorithms.hpp"

using namespace graph;

// Test for Graph algorithms
TEST_CASE("Test Graph algorithms") {
    Graph g(5);

    // Test adding edges
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 9);

    // Test BFS
    SUBCASE("Test BFS") {
        Graph bfsResult = Algorithms::bfs(g, 0);
        const auto& adjList = bfsResult.getAdjacency(0);

        // Allow either 1 or 2 neighbors, depending on order of traversal
        CHECK(adjList.getSize() >= 1);
    }

    // Test DFS
    SUBCASE("Test DFS") {
        Graph dfsResult = Algorithms::dfs(g, 0);
        const auto& adjList = dfsResult.getAdjacency(0);

        // Allow either 1 or 2 neighbors, depending on order of traversal
        CHECK(adjList.getSize() >= 1);
    }

    // Test Dijkstra
    SUBCASE("Test Dijkstra") {
        Graph dijkstraResult = Algorithms::dijkstra(g, 0);
        const auto& adjList = dijkstraResult.getAdjacency(0);

        CHECK(adjList.getSize() >= 1);  // At least 1 reachable vertex
    }

    // Test Prim's Algorithm
    SUBCASE("Test Prim's") {
        Graph primResult = Algorithms::prim(g);
        const auto& adjList = primResult.getAdjacency(0);

        CHECK(primResult.getNumOfVertices() == 5);
        CHECK(adjList.getSize() >= 1);  // MST must include something
    }

    // Test Kruskal's Algorithm
    SUBCASE("Test Kruskal's") {
        Graph kruskalResult = Algorithms::kruskal(g);
        const auto& adjList = kruskalResult.getAdjacency(0);

        CHECK(kruskalResult.getNumOfVertices() == 5);
        CHECK(adjList.getSize() >= 1);  // MST must include something
    }
}
