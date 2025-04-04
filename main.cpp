#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace graph;

int main() {
    try {
        // Create a graph with 6 vertices
        Graph g(6);

        // Add edges that form a tree structure
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(4, 5);

        // Add some extra edges that should NOT appear in the BFS/DFS trees
        g.addEdge(1, 2); // Creates a cycle
        g.addEdge(3, 5); // Connects across branches

        std::cout << "Original graph:\n";
        g.print_graph();

        std::cout << "\n=== BFS Tree from vertex 0 ===\n";
        Graph bfsTree = Algorithms::bfs(g, 0);
        bfsTree.print_graph();

        std::cout << "\n=== DFS Tree from vertex 0 ===\n";
        Graph dfsTree = Algorithms::dfs(g, 0);
        dfsTree.print_graph();

    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
