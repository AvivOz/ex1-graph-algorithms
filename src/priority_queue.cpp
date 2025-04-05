// Author: avivoz4@gmail.com

#include "../include/priority_queue.hpp"
#include <stdexcept>

using namespace graph;

PriorityQueue::PriorityQueue(int maxVertices)
    : size(0), capacity(maxVertices) {
    data = new HeapNode[capacity];       // Allocate memory for heap data array
    positions = new int[capacity];       // Allocate memory for positions array
}

PriorityQueue::~PriorityQueue() {
    delete[] data;        // Free memory allocated for data array
    delete[] positions;    // Free memory allocated for positions array
}

void PriorityQueue::insert(int vertex, int newDistance) {
    if (size == capacity) {
        throw std::overflow_error("Heap is full.");
    }

    HeapNode node{vertex, newDistance};
    data[size] = node;
    heapifyUp(size);         // Restore heap property after insertion
    positions[vertex] = size;
    size++;
}

HeapNode PriorityQueue::extractMin() {
    if (size == 0) {
        throw std::underflow_error("Heap is empty.");
    }

    HeapNode minNode = data[0];
    data[0] = data[size - 1];
    size--;
    heapifyDown(0);          // Restore heap property after extraction

    return minNode;
}

void PriorityQueue::decreaseKey(int vertex, int newDistance) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (data[i].vertex == vertex) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        throw std::runtime_error("Vertex not found.");
    }

    if (newDistance > data[index].distance) {
        throw std::runtime_error("New distance is greater than the current distance.");
    }

    data[index].distance = newDistance;
    heapifyUp(index);         // Restore heap property after key decrease
}

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0 && data[index] < data[(index - 1) / 2]) {
        swapNodes(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void PriorityQueue::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < size && data[leftChild] < data[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < size && data[rightChild] < data[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swapNodes(index, smallest);
        heapifyDown(smallest);
    }
}

void PriorityQueue::swapNodes(int i, int j) {
    HeapNode temp = data[i];
    data[i] = data[j];
    data[j] = temp;

    // Update positions array
    positions[data[i].vertex] = i;
    positions[data[j].vertex] = j;
}
