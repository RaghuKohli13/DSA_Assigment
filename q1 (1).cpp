/*
1) Develop a menu driven program demonstrating the following operations on
simple Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/
#include "Queue.hpp"

#include <iostream>

using namespace std;

void q1() {
    Queue<int> que;

    while (true) {
        cout << R"(---MENU---
1. Enqueue/Push
2. Dequeue/Pop
3. Is empty?
4. Is full?
5. Display
6. Peek/Front
7. Exit
Option: )";

        int opt;
        cin >> opt;

        switch (opt) {
            case 1: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                que.enqueue(val);
                break;
            }
            case 2: {
                cout << "Popping ...\n";
                que.dequeue();
                break;
            }
            case 3: {
                cout << "Is empty? " << (que.isEmpty() ? "true" : "false")
                     << '\n';
                break;
            }
            case 4: {
                cout << "Is full? " << (que.isFull() ? "true" : "false")
                     << '\n';
                break;
            }
            case 5: {
                cout << "Displaying queue items:\n";
                que.display();
                break;
            }
            case 6: {
                cout << "Top item: " << *que.front() << '\n';
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
