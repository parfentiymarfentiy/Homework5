#ifndef QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* frontPtr;
    Node* rearPtr;
    int count;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}
    
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
    
    void push(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            frontPtr = rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        count++;
    }
    
    void pop() {
        if (empty()) return;
        
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        count--;
        
        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }
    }
    
    T& front() {
        return frontPtr->data;
    }
    
    const T& front() const {
        return frontPtr->data;
    }
    
    bool empty() const {
        return frontPtr == nullptr;
    }
    
    int size() const {
        return count;
    }
};
