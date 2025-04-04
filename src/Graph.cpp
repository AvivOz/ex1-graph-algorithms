#include "../include/Graph.hpp"
#include <stdexcept>

namespace graph {

    Graph::Graph(int n) : numOfVertices(n) {
        adjacencyList = new List<Edge>[numOfVertices];
    }

    Graph::~Graph() {
        delete[] adjacencyList;
    }

    void Graph::addEdge(int sourceVertex, int destinationVertex, int weight, bool directed) {
        if (sourceVertex < 0 || sourceVertex >= numOfVertices || destinationVertex < 0 || destinationVertex >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        Edge edgeToDest{destinationVertex, weight};
        adjacencyList[sourceVertex].insert(edgeToDest);

        if (!directed) {
            Edge edgeToSrc{sourceVertex, weight};
            adjacencyList[destinationVertex].insert(edgeToSrc);
        }
    }

    void Graph::removeEdge(int sourceVertex, int destinationVertex) {
        if (sourceVertex < 0 || sourceVertex >= numOfVertices || destinationVertex < 0 || destinationVertex >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        Edge edgeToDest{destinationVertex, 0};  // weight is ignored in operator==
        Edge edgeToSrc{sourceVertex, 0};

        bool removedFromSource = adjacencyList[sourceVertex].remove(edgeToDest);
        bool removedFromDest = adjacencyList[destinationVertex].remove(edgeToSrc);

        if (!removedFromSource || !removedFromDest) {
            throw std::runtime_error("Edge does not exist");
        }
    }

    void Graph::print_graph() const {
        for (int i = 0; i < numOfVertices; ++i) {
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
