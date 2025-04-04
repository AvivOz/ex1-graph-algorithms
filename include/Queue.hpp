#pragma once
#include <iostream>

namespace graph {

    /**
     * @brief A simple generic queue implemented using a singly linked list.
     * 
     * Supports standard enqueue and dequeue operations.
     * Used in algorithms such as BFS.
     * 
     * @tparam T The type of elements stored in the queue.
     */
    template<typename T>
    class Queue {
    private:

        /**
         * @brief Node structure for the internal linked list.
         */
        struct Node {
            T data;     ///< The value stored in the node.
            Node* next; ///< Pointer to the next node.

            /**
             * @brief Constructs a node with the given value.
             * @param value The value to store in the node.
             */
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* front; ///< Pointer to the head of the queue.
        Node* rear;  ///< Pointer to the tail of the queue.

    public:
        /**
         * @brief Constructs an empty queue.
         */
        Queue();

        /**
         * @brief Destructor – deletes all nodes in the queue.
         */
        ~Queue();

        /**
         * @brief Inserts a new element at the end of the queue.
         * 
         * @param value The value to insert.
         */
        void enqueue(const T& value);

        /**
         * @brief Removes and returns the element at the front of the queue.
         * 
         * @return The value that was at the front.
         * @throws std::runtime_error if the queue is empty.
         */
        T dequeue();

        /**
         * @brief Checks whether the queue is empty.
         * 
         * @return true if the queue is empty, false otherwise.
         */
        bool isEmpty() const;
    };

    // --- Implementation ---

    template <typename T>
    Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

    template <typename T>
    Queue<T>::~Queue() {
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current->next;
            delete current;
            current = temp;
        }
    }

    template <typename T>
    void Queue<T>::enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    template <typename T> 
    T Queue<T>::dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }

        Node* temp = front;
        T value = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    template <typename T>
    bool Queue<T>::isEmpty() const {
        return front == nullptr;
    }

}
