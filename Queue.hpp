#pragma once
#include <iostream>

namespace graph {

    template<typename T>
    class Queue {
        private:

            struct Node {
                
                T data;
                Node* next;

                Node(const T& value) : data(value), next(nullptr) {}
            };

            Node* front; // Pointer to the head of the queue
            Node* rear; // Pointer to the tail of the queue
        
        public:

            Queue(); // Queue constructor 
            ~Queue(); // Queue destructor
            
            void enqueue(const T& value); // Insert a new element to the queue
            T dequeue(); // Pop the head of the queue and returns it's value
            bool isEmpty() const; // Check if the queue is empty. true if is empty, false otherwise.    
    };

    template <typename T>
    Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

    template <typename T>
    Queue<T>::~Queue() {

        Node* current = front;

        while(current != nullptr) {
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
            rear = front;
        }

        delete temp;
        return value;
    }

    template <typename T>
    bool Queue<T>::isEmpty() const {
        return front == nullptr;
    }


}

