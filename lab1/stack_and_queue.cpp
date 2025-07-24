#include <iostream>

class Queue {
private:
    static const int MAX = 100;
    int arr[MAX];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() : frontIndex(0), rearIndex(-1), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAX; }

    void enqueue(int value) {
        if (!isFull()) {
            rearIndex = (rearIndex + 1) % MAX;
            arr[rearIndex] = value;
            count++;
        } else {
            std::cout << "Queue full\n";
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            frontIndex = (frontIndex + 1) % MAX;
            count--;
        } else {
            std::cout << "Queue empty\n";
        }
    }

    int front() {
        if (!isEmpty()) {
            return arr[frontIndex];
        }
        throw std::out_of_range("Queue is empty");
    }

    int rear() {
        if (!isEmpty()) {
            return arr[rearIndex];
        }
        throw std::out_of_range("Queue is empty");
    }
};


class Stack {
private:
    static const int MAX = 100;
    int arr[MAX];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == MAX - 1; }

    void push(int value) {
        if (!isFull()) {
            arr[++topIndex] = value;
        } else {
            std::cout << "Stack overflow\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        } else {
            std::cout << "Stack underflow\n";
        }
    }

    int top() {
        if (!isEmpty()) {
            return arr[topIndex];
        }
        throw std::out_of_range("Stack is empty");
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "Top: " << s.top() << "\n"; // 20
    s.pop();
    std::cout << "Top after pop: " << s.top() << "\n"; // 10

    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    std::cout << "Front: " << q.front() << "\n"; // 100
    std::cout << "Rear: " << q.rear() << "\n";   // 200
    q.dequeue();
    std::cout << "New Front: " << q.front() << "\n"; // 200

    return 0;
}