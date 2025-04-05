// Author: avivoz4@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/graph.hpp"
#include "../include/queue.hpp"
#include "../include/priority_queue.hpp"
#include "../include/union_find.hpp"
#include "../include/list.hpp"

using namespace graph;

// Test for Graph class
TEST_CASE("Test Graph class") {
    Graph g(5);

    // Test adding edges
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 9);

    SUBCASE("Graph adjacency list") {
        const auto& adjList = g.getAdjacency(0);
        CHECK(adjList.getSize() == 2);  // Vertex 0 should have 2 neighbors
    }

    SUBCASE("Check if edge exists") {
        const auto& adjList = g.getAdjacency(0);
        CHECK(adjList.contains(Edge{1, 10}));
        CHECK(adjList.contains(Edge{3, 1}));
    }

    SUBCASE("Remove edge") {
        g.removeEdge(0, 1);
        const auto& adjList = g.getAdjacency(0);
        CHECK(adjList.getSize() == 1);  // After removing, vertex 0 should have 1 neighbor
    }

    SUBCASE("Check invalid remove") {
        g.removeEdge(0, 1); // Remove once
        CHECK_THROWS_AS(g.removeEdge(0, 1), std::runtime_error); // Now should throw
    }

    SUBCASE("Test graph printing") {
        std::ostringstream oss;
        g.print_graph(oss);
        CHECK(oss.str() != "");
    }
}

// Test for Queue class
TEST_CASE("Test Queue class") {
    Queue<int> q;

    SUBCASE("Test enqueue and dequeue") {
        q.enqueue(5);
        q.enqueue(10);

        CHECK(q.dequeue() == 5);  // First element should be 5
        CHECK(q.dequeue() == 10); // Second element should be 10
    }

    SUBCASE("Test isEmpty") {
        CHECK(q.isEmpty() == true);
        q.enqueue(5);
        CHECK(q.isEmpty() == false);
    }

    SUBCASE("Test size") {
        q.enqueue(20);
        CHECK(q.size() == 1);  // Should be 1 after enqueueing one element
    }
}

// Test for PriorityQueue (MinHeap) class
TEST_CASE("Test PriorityQueue (MinHeap) class") {
    PriorityQueue pq(10); // Using MinHeap instead of PriorityQueue

    SUBCASE("Test insert and extractMin") {
        pq.insert(1, 10);
        pq.insert(2, 5);
        pq.insert(3, 15);

        CHECK(pq.extractMin().vertex == 2);  // Min value is 5, corresponding to vertex 2
        CHECK(pq.extractMin().vertex == 1);  // Next min value is 10
    }

    SUBCASE("Test decreaseKey") {
        pq.insert(1, 10);
        pq.insert(2, 5);
        pq.decreaseKey(1, 3);  // Decrease key of vertex 1 to 3

        CHECK(pq.extractMin().vertex == 1);  // Vertex 1 should now be extracted first
    }

    SUBCASE("Test heap property") {
        pq.insert(1, 10);
        pq.insert(2, 5);
        pq.insert(3, 1);
        pq.insert(4, 7);
        pq.insert(5, 3);

        CHECK(pq.extractMin().vertex == 3);  // Should be extracted first because it has the smallest key
        CHECK(pq.extractMin().vertex == 5);
        CHECK(pq.extractMin().vertex == 2);
        CHECK(pq.extractMin().vertex == 4);
        CHECK(pq.extractMin().vertex == 1);  // Last element should be the largest
    }

    SUBCASE("Test underflow") {
        CHECK_THROWS_AS(pq.extractMin(), std::underflow_error);
    }

    SUBCASE("Test overflow") {
        PriorityQueue fullPQ(2);
        fullPQ.insert(1, 10);
        fullPQ.insert(2, 20);
        CHECK_THROWS_AS(fullPQ.insert(3, 30), std::overflow_error);
    }
}

// Test for UnionFind class
TEST_CASE("Test UnionFind class") {
    UnionFind uf(5);

    SUBCASE("Test find and union") {
        uf.unionSets(0, 1);
        uf.unionSets(2, 3);

        CHECK(uf.find(0) == uf.find(1));  // 0 and 1 should be in the same set
        CHECK(uf.find(2) == uf.find(3));  // 2 and 3 should be in the same set
        CHECK(uf.find(0) != uf.find(2)); // 0 and 2 should be in different sets
    }

    SUBCASE("Test path compression") {
        uf.unionSets(0, 1);
        uf.unionSets(1, 2);
        CHECK(uf.find(2) == uf.find(0)); // Path compression should make 0 and 2 connected
    }

    SUBCASE("Test invalid find") {
        CHECK_THROWS_AS(uf.find(10), std::out_of_range);
    }

    SUBCASE("Test multiple unions") {
        uf.unionSets(0, 1);
        uf.unionSets(2, 3);
        uf.unionSets(1, 2);
        CHECK(uf.find(0) == uf.find(2));  // 0 and 2 should be in the same set after union
    }
}