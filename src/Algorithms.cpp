#include "../include/Algorithms.hpp"
#include "../include/Utils.hpp"
#include "../include/Graph.hpp"
#include "../include/PriorityQueue.hpp"
#include "../include/UnionFind.hpp"
#include "../include/Queue.hpp"
#include "../include/List.hpp"

#include <stdexcept>
#include <climits>

namespace graph {

    Graph Algorithms::bfs(const Graph& g, int sourceVertex) {
        checkGraphNotEmpty(g);
        checkValidVertex(g, sourceVertex);

        int n = g.getNumOfVertices();
        Graph bfsTree(n);
        Queue<int> q;
        bool* visited = new bool[n]{false};

        visited[sourceVertex] = true;
        q.enqueue(sourceVertex);

        while (!q.isEmpty()) {
            int u = q.dequeue();

            const List<Edge>& neighbors = g.getAdjacency(u);
            List<Edge>::Node* node = neighbors.getHead();

            while (node != nullptr) {
                int v = node->data.dest;
                if (!visited[v]) {
                    visited[v] = true;
                    q.enqueue(v);
                    bfsTree.addEdge(u, v, node->data.weight, true);
                }
                node = node->next;
            }
        }

        delete[] visited;
        return bfsTree;
    }

    static void dfsVisit(const Graph& g, int u, bool* visited, Graph& dfsTree) {
        visited[u] = true;

        const List<Edge>& neighbors = g.getAdjacency(u);
        List<Edge>::Node* node = neighbors.getHead();

        while (node != nullptr) {
            int v = node->data.dest;
            if (!visited[v]) {
                dfsTree.addEdge(u, v, node->data.weight, true);
                dfsVisit(g, v, visited, dfsTree);
            }
            node = node->next;
        }
    }

    Graph Algorithms::dfs(const Graph& g, int sourceVertex) {
        checkGraphNotEmpty(g);
        checkValidVertex(g, sourceVertex);

        int n = g.getNumOfVertices();
        Graph dfsTree(n);
        bool* visited = new bool[n]{false};

        dfsVisit(g, sourceVertex, visited, dfsTree);

        delete[] visited;
        return dfsTree;
    }

    Graph Algorithms::dijkstra(const Graph& g, int sourceVertex) {
        checkGraphNotEmpty(g);
        checkValidVertex(g, sourceVertex);

        int n = g.getNumOfVertices();
        Graph shortestPathTree(n);
        int* distance = new int[n];

        for (int i = 0; i < n; ++i) {
            distance[i] = INT_MAX;
        }
        distance[sourceVertex] = 0;

        MinHeap heap(n);
        for (int i = 0; i < n; ++i) {
            heap.insert(i, distance[i]);
        }

        while (!heap.isEmpty()) {
            HeapNode current = heap.extractMin();
            int u = current.vertex;

            const List<Edge>& neighbors = g.getAdjacency(u);
            List<Edge>::Node* node = neighbors.getHead();

            while (node != nullptr) {
                int v = node->data.dest;
                int weight = node->data.weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    heap.decreaseKey(v, distance[v]);
                    shortestPathTree.addEdge(u, v, weight, true);
                }

                node = node->next;
            }
        }

        delete[] distance;
        return shortestPathTree;
    }

    Graph Algorithms::prim(const Graph& g) {
        checkGraphNotEmpty(g);

        int n = g.getNumOfVertices();
        Graph mst(n);

        int* key = new int[n];
        int* parent = new int[n];
        bool* inMST = new bool[n];

        for (int i = 0; i < n; ++i) {
            key[i] = INT_MAX;
            parent[i] = -1;
            inMST[i] = false;
        }

        key[0] = 0;
        MinHeap heap(n);
        for (int i = 0; i < n; ++i) {
            heap.insert(i, key[i]);
        }

        while (!heap.isEmpty()) {
            HeapNode minNode = heap.extractMin();
            int u = minNode.vertex;
            inMST[u] = true;

            const List<Edge>& neighbors = g.getAdjacency(u);
            List<Edge>::Node* node = neighbors.getHead();

            while (node != nullptr) {
                int v = node->data.dest;
                int weight = node->data.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    heap.decreaseKey(v, weight);
                }

                node = node->next;
            }
        }

        for (int v = 1; v < n; ++v) {
            int u = parent[v];
            int weight = key[v];
            if (u != -1) {
                mst.addEdge(u, v, weight, false);
            }
        }

        delete[] key;
        delete[] parent;
        delete[] inMST;

        return mst;
    }

    Graph Algorithms::kruskal(const Graph& g) {
        checkGraphNotEmpty(g);

        int n = g.getNumOfVertices();
        Graph mst(n);
        UnionFind uf(n);

        struct TempEdge {
            int u, v, w;
        };

        int edgeCount = 0;
        for (int u = 0; u < n; ++u) {
            const List<Edge>& neighbors = g.getAdjacency(u);
            List<Edge>::Node* node = neighbors.getHead();
            while (node != nullptr) {
                int v = node->data.dest;
                if (u < v) edgeCount++;
                node = node->next;
            }
        }

        TempEdge* edges = new TempEdge[edgeCount];
        int index = 0;

        for (int u = 0; u < n; ++u) {
            const List<Edge>& neighbors = g.getAdjacency(u);
            List<Edge>::Node* node = neighbors.getHead();
            while (node != nullptr) {
                int v = node->data.dest;
                int w = node->data.weight;

                if (u < v) {
                    edges[index++] = {u, v, w};
                }

                node = node->next;
            }
        }

        for (int i = 0; i < edgeCount - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < edgeCount; ++j) {
                if (edges[j].w < edges[minIndex].w) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                TempEdge temp = edges[i];
                edges[i] = edges[minIndex];
                edges[minIndex] = temp;
            }
        }

        for (int i = 0; i < edgeCount; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            if (uf.find(u) != uf.find(v)) {
                uf.unionSets(u, v);
                mst.addEdge(u, v, w, false);
            }
        }

        delete[] edges;
        return mst;
    }

}
