/*
4) Write a program to find first non-repeating character in a string using
Queue. Sample I/P: a a b c Sample O/P: a -1 b b
*/
#include "Queue.hpp"

#include <iostream>
#include <string>

using namespace std;

static const int ALPHABETS = 26;

void q4() {
    cout << "Finding first non-repeating character in a string using Queue.\n";
    cout << "Enter a string of alphabets: ";
    string str;
    getline(cin, str);

    Queue<char> que(ALPHABETS);

    string res;

    for (const char& ch : str) {
        if (que.isEmpty()) {
            res += ch;
            que.enqueue(ch);
        } else {
            char front = *que.front();
            if (front == ch) {
                que.dequeue();
                if (que.isEmpty()) res += '#';
                else res += *que.front();
            } else {
                res += front;
                que.enqueue(ch);
            }
        }
    }
    cout << res << '\n';
}
