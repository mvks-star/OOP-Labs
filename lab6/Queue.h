#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

// Шаблонний клас "Черга" на основі зв'язаного списку
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* frontNode; // Початок черги
    Node* rearNode;  // Кінець черги
    int elementCount;// Кількість елементів

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), elementCount(0) {}

    ~Queue() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    bool IsEmpty() const {
        return frontNode == nullptr;
    }

    void Push(const T& val) {
        Node* newNode = new Node(val);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        elementCount++;
    }

    T Pop() {
        if (IsEmpty()) {
            throw out_of_range("Queue is empty! Cannot pop element.");
        }
        Node* temp = frontNode;
        T val = temp->data;
        
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        
        delete temp;
        elementCount--;
        return val;
    }

    void Print() const {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = frontNode;
        cout << "Queue (front -> rear): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int GetCount() const {
        return elementCount;
    }
};