// Author: avivoz4@gmail.com

#pragma once
#include <stdexcept>

namespace graph {

    /**
     * @brief Node structure for the priority queue (MinHeap).
     * Represents a single node in the heap with a vertex and its associated distance.
     */
    struct HeapNode {
        int vertex;   ///< The vertex index.
        int distance; ///< The distance value associated with the vertex.

        /**
         * @brief Equality operator for comparing two HeapNode objects.
         * Compares based on both vertex and distance.
         * @param other The other HeapNode to compare.
         * @return True if both vertex and distance are the same.
         */
        bool operator==(const HeapNode& other) const {
            return vertex == other.vertex && distance == other.distance;
        }

        /**
         * @brief Less-than operator for comparing HeapNode objects.
         * Compares based on distance.
         * @param other The other HeapNode to compare.
         * @return True if this node's distance is less than the other.
         */
        bool operator<(const HeapNode& other) const {
            return distance < other.distance;
        }

        /**
         * @brief Greater-than operator for comparing HeapNode objects.
         * Compares based on distance.
         * @param other The other HeapNode to compare.
         * @return True if this node's distance is greater than the other.
         */
        bool operator>(const HeapNode& other) const {
            return distance > other.distance;
        }
    };

    /**
     * @brief Represents a MinHeap-based priority queue.
     * This queue is used to efficiently retrieve the vertex with the minimum distance.
     */
    class PriorityQueue {
    private:
        HeapNode* data;    ///< The array of heap nodes (dynamically allocated).
        int* positions;    ///< The array to track positions of vertices in the heap (dynamically allocated).
        int size;          ///< The current size of the heap (number of elements).
        int capacity;      ///< The maximum capacity of the heap (fixed size).

        /**
         * @brief Moves a node up the heap to restore the heap property.
         * @param index The index of the node to move.
         */
        void heapifyUp(int index);

        /**
         * @brief Moves a node down the heap to restore the heap property.
         * @param index The index of the node to move.
         */
        void heapifyDown(int index);

        /**
         * @brief Swaps two nodes in the heap.
         * @param i The index of the first node.
         * @param j The index of the second node.
         */
        void swapNodes(int i, int j);

    public:
        /**
         * @brief Constructs a PriorityQueue with a given maximum capacity.
         * @param maxVertices Maximum number of vertices (heap capacity).
         */
        PriorityQueue(int maxVertices);

        /**
         * @brief Destructor that frees dynamically allocated memory.
         */
        ~PriorityQueue();

        /**
         * @brief Inserts a vertex with a given distance into the heap.
         * If the vertex is already present, the priority is updated.
         * @param vertex The vertex index.
         * @param newDistance The distance value associated with the vertex.
         */
        void insert(int vertex, int newDistance);

        /**
         * @brief Extracts the vertex with the minimum distance.
         * @return The vertex with the minimum distance.
         * @throws std::underflow_error if the heap is empty.
         */
        HeapNode extractMin();

        /**
         * @brief Decreases the distance value of a vertex in the heap.
         * @param vertex The vertex index.
         * @param newDistance The new distance value.
         * @throws std::runtime_error if the new distance is greater than the current distance.
         */
        void decreaseKey(int vertex, int newDistance);

        /**
         * @brief Returns true if the heap is empty.
         * @return True if the heap is empty, otherwise false.
         */
        bool isEmpty() const;
    };

}  
