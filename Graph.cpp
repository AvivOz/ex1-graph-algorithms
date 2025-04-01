#include "Graph.hpp"
#include <stdexcept>

namespace graph {

    Graph::Graph(int n) : numOfVertices(n) {
        adjacencyList = new List<Edge>[numOfVertices];
    }

    Graph::~Graph() {
        delete[] adjacencyList;
    }

    void Graph::addEdge(int sourceVertex, int destinationVertex, int weight) {

        // Check if the vertices are in valid bounds
        if (sourceVertex < 0 || sourceVertex >= numOfVertices || destinationVertex < 0 || destinationVertex >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        // Create Edge objects for both directions since the graph is undirected
        Edge edgeToDest{destinationVertex, weight};
        Edge edgeToSrc{sourceVertex, weight};

        // Insert the edges into both adjacency lists
        adjacencyList[sourceVertex].insert(edgeToDest);
        adjacencyList[destinationVertex].insert(edgeToSrc); 

    }

    void Graph::removeEdge(int sourceVertex, int destinationVertex) {

        // Check if the vertices are in valid bounds
        if (sourceVertex < 0 || sourceVertex >= numOfVertices || destinationVertex < 0 || destinationVertex >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        // Create temporary Edge objects to match and remove
        // Weight is irrelevant because equality is based on destination only
        Edge edgeToDest{destinationVertex, 0};
        Edge edgeToSource{sourceVertex, 0};

        // Attempt to remove the edge from both sides (since the graph is undirected)
        bool removedFromSource = adjacencyList[sourceVertex].remove(edgeToDest);
        bool removedFromDest = adjacencyList[destinationVertex].remove(edgeToSource);
        
        // If either removal failed, the edge didn't exist
        if(!removedFromSource || !removedFromDest) {
            throw std::runtime_error("Edge does not exist");
        }
    }

    void Graph::print_graph() const {

        for (int i = 0; i < numOfVertices; i++) {
            std::cout << "Vertex " << i << ": ";
            adjacencyList[i].print(); 
            std::cout << std::endl;
        }
    }

    const List<Edge>& Graph::getAdjacency(int vertex) const {
        if (vertex < 0 || vertex >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        return adjacencyList[vertex];
    }

}