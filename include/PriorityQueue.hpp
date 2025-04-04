#pragma once

namespace graph {

    /**
     * @brief A structure representing a node in the min-heap.
     * 
     * Each node contains:
     * - vertex: the index of the vertex.
     * - distance: the current distance from the source vertex (used as priority).
     */
    struct HeapNode {
        int vertex;   ///< The index of the vertex.
        int distance; ///< The distance from the source node.
    };

    /**
     * @brief A min-heap implementation for use in Dijkstra's and Prim's algorithms.
     * 
     * Maintains a priority queue of vertices based on their distances.
     */
    class MinHeap {
    private:
        HeapNode* data;    ///< Array of heap nodes.
        int* positions;    ///< Maps vertex number to its index in the heap.
        int capacity;      ///< Maximum number of vertices the heap can hold.
        int size;          ///< Current number of elements in the heap.

        /**
         * @brief Restores the heap property by moving a node up the tree.
         * 
         * Called after insertions or decreaseKey.
         * 
         * @param index The index of the node to heapify upwards.
         */
        void heapifyUp(int index);

        /**
         * @brief Restores the heap property by moving a node down the tree.
         * 
         * Called after extracting the minimum node.
         * 
         * @param index The index of the node to heapify downwards.
         */
        void heapifyDown(int index);

        /**
         * @brief Swaps two nodes in the heap and updates their positions.
         * 
         * @param i Index of the first node.
         * @param j Index of the second node.
         */
        void swapNodes(int i, int j);

    public:
        /**
         * @brief Constructs a MinHeap with a given maximum capacity.
         * 
         * @param maxVertices The maximum number of vertices the heap can store.
         */
        MinHeap(int maxVertices);

        /**
         * @brief Destructor – frees all dynamically allocated memory.
         */
        ~MinHeap();

        /**
         * @brief Inserts a new vertex with the given distance into the heap.
         * 
         * @param vertex The vertex to insert.
         * @param distance The initial distance (priority) of the vertex.
         * @throws std::overflow_error if the heap is full.
         */
        void insert(int vertex, int distance);

        /**
         * @brief Extracts the node with the minimum distance from the heap.
         * 
         * @return The HeapNode with the smallest distance.
         * @throws std::underflow_error if the heap is empty.
         */
        HeapNode extractMin();

        /**
         * @brief Updates the distance (priority) of a given vertex in the heap.
         * 
         * Assumes the new distance is smaller than the current one.
         * 
         * @param vertex The vertex to update.
         * @param newDistance The new, smaller distance to assign.
         */
        void decreaseKey(int vertex, int newDistance);

        /**
         * @brief Checks whether the heap is empty.
         * 
         * @return true if the heap is empty, false otherwise.
         */
        bool isEmpty() const;
    };

}
