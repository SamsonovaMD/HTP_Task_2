#pragma once

#ifdef SINGLELINKEDLIST_EXPORTS
#define SINGLELINKEDLIST __declspec(dllexport)
#else
#define SINGLELINKEDLIST __declspec(dllimport)
#endif

#include <iostream>

template<typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    SingleLinkedList() : head(nullptr) {}

    ~SingleLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAfter(const T& prevValue, const T& value) {
        Node* newNode = new Node(value);
        Node* current = head;
        while (current) {
            if (current->data == prevValue) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        std::cerr << "Element " << prevValue << " not found" << std::endl;
    }

    void remove(const T& value) {
        if (!head)
            return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current) {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    bool search(const T& value) const {
        Node* current = head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
