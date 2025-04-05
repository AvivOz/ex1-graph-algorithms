// Author: avivoz4@gmail.com

#include <iostream>
#include "include/graph.hpp"
#include "include/algorithms.hpp"
#include "include/union_find.hpp"
#include "include/priority_queue.hpp"
#include "include/queue.hpp"
#include "include/utils.hpp"

using namespace graph;

int main() {
    // Create a new graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 9);

    // Print the graph before running any algorithms
    std::cout << "Graph before running any algorithm:" << std::endl;
    g.print_graph(std::cout); // Pass std::cout as argument

    // Demonstrate Dijkstra's algorithm
    std::cout << "\nRunning Dijkstra from vertex 0:" << std::endl;
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree.print_graph(std::cout); // Pass std::cout as argument

    // Demonstrate BFS (Breadth-First Search)
    std::cout << "\nRunning BFS from vertex 0:" << std::endl;
    Graph bfsTree = Algorithms::bfs(g, 0);
    bfsTree.print_graph(std::cout); // Pass std::cout as argument

    // Demonstrate DFS (Depth-First Search)
    std::cout << "\nRunning DFS from vertex 0:" << std::endl;
    Graph dfsTree = Algorithms::dfs(g, 0);
    dfsTree.print_graph(std::cout); // Pass std::cout as argument

    // Demonstrate Prim's algorithm (Minimum Spanning Tree)
    std::cout << "\nRunning Prim's algorithm:" << std::endl;
    Graph primTree = Algorithms::prim(g);
    primTree.print_graph(std::cout); // Pass std::cout as argument

    std::cout << "The edges included in the Minimum Spanning Tree are:" << std::endl;
    for (int i = 0; i < primTree.getNumOfVertices(); ++i) {
        const List<Edge>& edges = primTree.getAdjacency(i);
        List<Edge>::Node* node = edges.getHead();
        while (node != nullptr) {
            std::cout << "(" << node->data.dest << ", " << node->data.weight << ")" << std::endl;
            node = node->next;
        }
    }

    // Demonstrate Kruskal's algorithm (Minimum Spanning Tree)
    std::cout << "\nRunning Kruskal's algorithm:" << std::endl;
    Graph kruskalTree = Algorithms::kruskal(g);
    kruskalTree.print_graph(std::cout); // Pass std::cout as argument

    std::cout << "The edges included in the Minimum Spanning Tree are:" << std::endl;
    for (int i = 0; i < kruskalTree.getNumOfVertices(); ++i) {
        const List<Edge>& edges = kruskalTree.getAdjacency(i);
        List<Edge>::Node* node = edges.getHead();
        while (node != nullptr) {
            std::cout << "(" << node->data.dest << ", " << node->data.weight << ")" << std::endl;
            node = node->next;
        }
    }

    return 0;
}