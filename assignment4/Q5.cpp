/*
5) Write a program to implement a stack using (a) Two queues and (b) One Queue.
*/
#include "Queue.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

static void two_queue_stack() {
    Queue<int> q1(100), q2(100);

    auto push = [&](int val) { q1.enqueue(val); };
    auto pop  = [&]() {
        if (q1.isEmpty()) return;
        // Fill q2 until last element
        while (q1.size() > 1) {
            q2.enqueue(*q1.front());
            q1.dequeue();
        }
        q1.dequeue();
        std::swap(q1, q2);
    };
    auto isEmpty = [&]() -> bool { return q1.isEmpty(); };
    auto isFull  = [&]() -> bool { return q1.isFull(); };
    auto display = [&]() {
        Queue<int> tmp = q1;
        std::vector<int> elems;
        while (!tmp.isEmpty()) {
            elems.push_back(*tmp.front());
            tmp.dequeue();
        }
        for (int i = elems.size() - 1; i >= 0; --i) {
            cout << elems[i] << '\n';
        }
    };
    auto peek = [&]() -> int {
        if (q1.isEmpty()) {
            throw std::runtime_error("empty stack");
        };
        // Emptying q1 and filling q2 until last element
        while (q1.size() > 1) {
            q2.enqueue(*q1.front());
            q1.dequeue();
        }
        int top = *q1.front();
        q2.enqueue(top);
        q1.dequeue();
        std::swap(q1, q2);
        return top;
    };

    cout << "Stack using two Queues.\n";

    while (true) {
        cout << R"(---MENU---
1. Push
2. Pop
3. Is empty?
4. Is full?
5. Display
6. Peek/Top
7. Exit
Option: )";

        int opt = -1;
        cin >> opt;

        switch (opt) {
            case 1: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;
            }
            case 2: {
                cout << "Popping ...\n";
                pop();
                break;
            }
            case 3: {
                cout << "Is empty? " << (isEmpty() ? "true" : "false") << '\n';
                break;
            }
            case 4: {
                cout << "Is full? " << (isFull() ? "true" : "false") << '\n';
                break;
            }
            case 5: {
                cout << "Displaying stack items:\n";
                display();
                break;
            }
            case 6: {
                cout << "Top item: " << peek() << '\n';
                break;
            }
            case 7: {
                cout << "Exiting ...\n";
                return;
            }
            default: break;
        }
    }
}

static void one_queue_stack() {
    Queue<int> q1(100);

    auto push = [&](int val) { q1.enqueue(val); };
    auto pop  = [&]() {
        if (q1.isEmpty()) return;
        // Rotate the queue to move last element to front
        int size = q1.size();
        while (size > 1) {
            q1.enqueue(*q1.front());
            q1.dequeue();
            size--;
        }
        q1.dequeue();
    };
    auto isEmpty = [&]() -> bool { return q1.isEmpty(); };
    auto isFull  = [&]() -> bool { return q1.isFull(); };
    auto display = [&]() {
        Queue<int> tmp = q1;
        std::vector<int> elems;
        while (!tmp.isEmpty()) {
            elems.push_back(*tmp.front());
            tmp.dequeue();
        }
        for (int i = elems.size() - 1; i >= 0; --i) {
            cout << elems[i] << '\n';
        }
    };
    auto peek = [&]() -> int {
        if (q1.isEmpty()) {
            throw std::runtime_error("empty stack");
        };
        // Rotate the queue to move last element to front
        int size = q1.size();
        while (size > 1) {
            q1.enqueue(*q1.front());
            q1.dequeue();
            size--;
        }
        int top = *q1.front();
        q1.enqueue(top);
        q1.dequeue();
        return top;
    };

    cout << "Stack using one Queue.\n";

    while (true) {
        cout << R"(---MENU---
1. Push
2. Pop
3. Is empty?
4. Is full?
5. Display
6. Peek/Top
7. Exit
Option: )";

        int opt = -1;
        cin >> opt;

        switch (opt) {
            case 1: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;
            }
            case 2: {
                cout << "Popping ...\n";
                pop();
                break;
            }
            case 3: {
                cout << "Is empty? " << (isEmpty() ? "true" : "false") << '\n';
                break;
            }
            case 4: {
                cout << "Is full? " << (isFull() ? "true" : "false") << '\n';
                break;
            }
            case 5: {
                cout << "Displaying stack items:\n";
                display();
                break;
            }
            case 6: {
                cout << "Top item: " << peek() << '\n';
                break;
            }
            case 7: {
                cout << "Exiting ...\n";
                return;
            }
            default: break;
        }
    }
}

void q5() {
    two_queue_stack();
    one_queue_stack();
}
