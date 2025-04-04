#include "../include/PriorityQueue.hpp"
#include <stdexcept>

using namespace graph;

MinHeap::MinHeap(int maxVertices) : capacity(maxVertices), size(0) {
    data = new HeapNode[capacity];
    positions = new int[capacity];
}

MinHeap::~MinHeap() {
    delete[] data;
    delete[] positions;
}

void MinHeap::heapifyUp(int index) {

    if (index < 0 || index >= capacity) {
        throw std::out_of_range("The index is out of range");
    } 

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (data[index].distance < data[parentIndex].distance) {
            swapNodes(index, parentIndex);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void MinHeap::heapifyDown(int index) {
    while (true) {
        int smallest = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if (left < size && data[left].distance < data[smallest].distance) {
            smallest = left;
        }
        if (right < size && data[right].distance < data[smallest].distance) {
            smallest = right;
        }

        if (smallest != index) {
            swapNodes(index, smallest);
            index = smallest;
        } else {
            break;
        }
    }
}

void MinHeap::swapNodes(int i, int j) {
    HeapNode temp = data[i];
    data[i] = data[j];
    data[j] = temp;

    // Position update
    positions[data[i].vertex] = i;
    positions[data[j].vertex] = j;
}

void MinHeap::insert(int vertex, int newDistance) {

    if (size >= capacity) {
        throw std::overflow_error("Heap is full");
    }

    data[size].vertex = vertex;
    data[size].distance = newDistance;
    positions[vertex] = size;

    // Update the heap if needed
    heapifyUp(size);

    // Update the current size of the heap
    size++;
}

HeapNode MinHeap::extractMin() {
    if (isEmpty()) {
        throw std::underflow_error("Heap is empty");
    }

    HeapNode minNode = data[0];
    data[0] = data[size - 1];
    positions[data[0].vertex] = 0;
    size--;

    heapifyDown(0);

    return minNode;
}

void MinHeap::decreaseKey(int vertex, int newDistance) {
    int index = positions[vertex];

    if (index >= size || index < 0) {
        throw std::out_of_range("Vertex not found in heap");
    }

    if (data[index].distance <= newDistance) {
        return; // no need to update if the new distance is not smaller
    }

    data[index].distance = newDistance;
    heapifyUp(index);
}

bool MinHeap::isEmpty() const {
    return size == 0;
}
