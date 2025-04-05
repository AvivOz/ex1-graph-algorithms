// Author: avivoz4@gmail.com

#include "../include/graph.hpp"
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
            throw std::out_of_range("Vertex index is out of range");
        }

        adjacencyList[sourceVertex].insert(Edge{destinationVertex, weight});
        if (!directed) {
            adjacencyList[destinationVertex].insert(Edge{sourceVertex, weight});
        }
    }

    void Graph::removeEdge(int sourceVertex, int destinationVertex) {
        if (sourceVertex < 0 || sourceVertex >= numOfVertices || destinationVertex < 0 || destinationVertex >= numOfVertices) {
            throw std::out_of_range("Vertex index is out of range");
        }

        bool removed = adjacencyList[sourceVertex].remove(Edge{destinationVertex, 0});
        if (!removed) {
            throw std::runtime_error("Edge does not exist");
        }
    }

    void Graph::print_graph(std::ostream& os) const {
        for (int i = 0; i < numOfVertices; ++i) {
            os << "Vertex " << i << ": ";
            const List<Edge>& adjList = adjacencyList[i];
            auto current = adjList.getHead();  // Start from the head
            while (current != nullptr) {
                const auto& edge = current->data;
                os << "(" << edge.dest << ", " << edge.weight << ") ";
                current = current->next;  // Move to next node
            }
            os << std::endl;
        }
    }

    const List<Edge>& Graph::getAdjacency(int vertex) const {
        if (vertex < 0 || vertex >= numOfVertices) {
            throw std::out_of_range("Vertex index is out of range");
        }
        return adjacencyList[vertex];
    }

}