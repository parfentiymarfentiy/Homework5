#ifndef QUEUE_PRIORITY_H

template <typename T>
class QueuePriority {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
        Node(const T& value, int prio) : data(value), priority(prio), next(nullptr) {}
    };
    
    Node* frontPtr;
    int count;

public:
    QueuePriority() : frontPtr(nullptr), count(0) {}
    
    ~QueuePriority() {
        while (!empty()) {
            pop();
        }
    }
    
    void push(const T& value, int priority) {
        Node* newNode = new Node(value, priority);
        
        if (empty() || priority > frontPtr->priority) {
            newNode->next = frontPtr;
            frontPtr = newNode;
        } else {
            Node* current = frontPtr;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        count++;
    }
    
    void pop() {
        if (empty()) return;
        
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        count--;
    }
