#include "Graph.hpp"
#include <iostream>

using namespace graph;

int main() {
    try {
        // Create a graph with 5 vertices (0 through 4)
        Graph g(5);

        // Add some undirected edges
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 5);
        g.addEdge(1, 2, 3);
        g.addEdge(3, 4, 7);

        std::cout << "Graph after adding edges:" << std::endl;
        g.print_graph();

        std::cout << "\nRemoving edge (0, 2)..." << std::endl;
        g.removeEdge(0, 2);  // Should succeed

        std::cout << "Graph after removing edge (0, 2):" << std::endl;
        g.print_graph();

        std::cout << "\nTrying to remove non-existent edge (0, 4)..." << std::endl;
        g.removeEdge(0, 4);  // Should throw an exception

    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
