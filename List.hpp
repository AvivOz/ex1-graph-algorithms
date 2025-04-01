#pragma once
#include <iostream>

namespace graph { 

    template <typename T>
    class List {
    public:

        // Node structure representing each element in the list
        struct Node {
            T data; // The value stored in the node
            Node* next; // Pointer to the next node in the list

            Node(const T& value) : data(value), next(nullptr) {} // Constructor for Node
        };

        Node* head; // Pointer to the first node in the list
        List(); // Constructor of the list
        ~List(); // Destructor of the list

        void insert(const T& value); // Inserts a new value at the end of the list
        bool remove(const T& value); // Removes the first node whose data matches the given value
        void print() const;  // Outputs the contents of the list to std::cout using the << operator for each element
        Node* getHead() const { // Returns a pointer to the first node in the list (head)
            return head;
        }
    

    };

    // Constructor: initializes an empty list
    template<typename T> 
    List<T>::List() : head(nullptr) {}
    
    // Destructor: deletes all nodes in the list to free memory
    template<typename T>
    List<T>::~List() {

        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Adds a new node with the given value at the end of the list
    template<typename T> 
    void List<T>::insert(const T& value) { 
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Removes the first node with the given value
    // Returns true if a node was removed, false otherwise
    template<typename T>
    bool List<T>::remove(const T& value) {

        
        if (head == nullptr) {
            return false; // List is empty
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr) {
            Node* next = current->next;

            if (next->data == value) {
                current->next = next->next;
                delete next;
                return true;
            }

            current = next;
        }

        return false; // Value not found
    }

    template <typename T>
    void List<T>::print() const {
        Node* current = head;
        while(current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

}