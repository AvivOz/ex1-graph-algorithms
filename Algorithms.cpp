#include "Algorithms.hpp"
#include "Queue.hpp"
#include "List.hpp"
#include <stdexcept>

namespace graph {

    Graph Algorithms::bfs(const Graph& g, int sourceVertex) {

        // Number of vertices in the input graph
        int n = g.getNumOfVertices();
        
        // Validate source vertex index
        if (sourceVertex < 0 || sourceVertex >= n) {
            throw std::out_of_range("Source vertex is out of range");
        }

        // Create an empty graph to hold the BFS tree
        Graph bfsTree(n);
        Queue<int> q;
        bool* visited = new bool[n]{false};

        // Start BFS from the source vertex
        visited[sourceVertex] = true;
        q.enqueue(sourceVertex); 

        // Main BFS loop
        while(!q.isEmpty()) {
            int current = q.dequeue();

            // Traverse all neighbors of the current vertex
            const List<Edge>& neighbors = g.getAdjacency(current);
            List<Edge>::Node* node = neighbors.getHead();
            
            while (node != nullptr) {

                int neighbor = node->data.dest;

                // If neighbor has not been visited, add to BFS tree and queue
                if (!visited[neighbor]) {

                    visited[neighbor] = true;
                    q.enqueue(neighbor);
                    bfsTree.addEdge(current, neighbor, node->data.weight);
                }

                node = node->next;
            }
        }

        // Free memory
        delete[] visited;

        return bfsTree;
    }

    static void dfsVisit(const Graph& g, int currentVertex, bool* visited, Graph& dfsTree) {
        
        visited[currentVertex] = true;

        const List<Edge>& neighbors  = g.getAdjacency(currentVertex);
        List<Edge>::Node* node = neighbors .getHead();

        while(node != nullptr) {

            int neighbor = node->data.dest;

            if(!visited[neighbor]) {
                dfsTree.addEdge(currentVertex, neighbor, node->data.weight);
                dfsVisit(g, neighbor, visited, dfsTree);
            }

            node = node->next;

        }
    }

    Graph Algorithms::dfs(const Graph& g, int sourceVertex) {

        int n = g.getNumOfVertices();

        if (sourceVertex < 0 || sourceVertex >= n) {
            throw std::out_of_range("Vertex is out of range");
        }

        Graph dfsTree(n);
        bool* visited = new bool[n]{false};

        dfsVisit(g, sourceVertex, visited, dfsTree);

        delete[] visited;
        return dfsTree;
    }
}