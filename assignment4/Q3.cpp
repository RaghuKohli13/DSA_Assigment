/*
3) Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/
#include "Queue.hpp"

#include <iostream>

using namespace std;

void q3() {
    cout << "Interleaving a queue of numbers.\n";
    cout << "Enter size (even): ";
    int n;
    cin >> n;
    if (n % 2 != 0) {
        n = n + 1;
        cout << "Size is not even, incrementing to " << n << '\n';
    }
    cout << "Enter elements: ";
    Queue<int> que(n);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        que.enqueue(val);
    }

    int mid = n / 2;
    Queue<int> temp(mid);
    while (mid > 0) {
        int val = *que.front();
        que.dequeue();
        temp.enqueue(val);
        mid--;
    }

    Queue<int> res(n);
    for (int i = 0; i < n / 2; ++i) {
        res.enqueue(*temp.front());
        res.enqueue(*que.front());
        temp.dequeue();
        que.dequeue();
    }

    res.display();
}
