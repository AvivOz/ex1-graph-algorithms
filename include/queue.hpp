// Author: avivoz4@gmail.com

#pragma once
#include <stdexcept>

namespace graph {

    /**
     * @brief Represents a queue data structure.
     */
    template <typename T>
    class Queue {
    private:
        struct Node {
            T data;  ///< The data held by the node.
            Node* next;  ///< Pointer to the next node in the queue.
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* front;  ///< Pointer to the front of the queue.
        Node* rear;   ///< Pointer to the rear of the queue.

    public:
        /**
         * @brief Constructs an empty queue.
         */
        Queue() : front(nullptr), rear(nullptr) {}

        /**
         * @brief Destructor – deletes all nodes in the queue.
         */
        ~Queue() {
            while (front != nullptr) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        /**
         * @brief Adds an element to the rear of the queue.
         * @param value The value to add.
         */
        void enqueue(const T& value) {
            Node* newNode = new Node(value);
            if (rear == nullptr) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        /**
         * @brief Removes and returns the element at the front of the queue.
         * @return The front element.
         * @throws std::underflow_error if the queue is empty.
         */
        T dequeue() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            T value = front->data;
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            return value;
        }

        /**
         * @brief Checks if the queue is empty.
         * @return True if the queue is empty, otherwise false.
         */
        bool isEmpty() const {
            return front == nullptr;
        }

        /**
         * @brief Returns the size of the queue.
         * @return The size of the queue.
         */
        int size() const {
            int count = 0;
            Node* current = front;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }
    };

}