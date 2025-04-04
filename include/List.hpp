#pragma once
#include <iostream>

namespace graph { 

    /**
     * @brief A singly linked list template class.
     * 
     * This generic list provides basic operations such as insert, remove, and print.
     * It is used internally to implement structures like the graph's adjacency list.
     * 
     * @tparam T The type of elements stored in the list.
     */
    template <typename T>
    class List {
    public:

        /**
         * @brief Node structure representing each element in the list.
         */
        struct Node {
            T data;     ///< The value stored in the node.
            Node* next; ///< Pointer to the next node in the list.

            /**
             * @brief Constructs a node with the given value.
             * @param value The value to store in the node.
             */
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* head; ///< Pointer to the first node in the list.

        /**
         * @brief Constructs an empty list.
         */
        List();

        /**
         * @brief Destructor – deletes all nodes in the list.
         */
        ~List();

        /**
         * @brief Inserts a new value at the end of the list.
         * 
         * @param value The value to insert.
         */
        void insert(const T& value);

        /**
         * @brief Removes the first node whose data matches the given value.
         * 
         * @param value The value to remove.
         * @return true if a node was removed; false otherwise.
         */
        bool remove(const T& value);

        /**
         * @brief Outputs the contents of the list to std::cout.
         * 
         * Uses the << operator for each element.
         */
        void print() const;

        /**
         * @brief Returns a pointer to the first node in the list (head).
         * 
         * @return A pointer to the first node.
         */
        Node* getHead() const {
            return head;
        }
    };

    // ---- Implementation ----

    template<typename T> 
    List<T>::List() : head(nullptr) {}

    template<typename T>
    List<T>::~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

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

    template<typename T>
    bool List<T>::remove(const T& value) {
        if (head == nullptr) return false;

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

        return false;
    }

    template <typename T>
    void List<T>::print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

}
