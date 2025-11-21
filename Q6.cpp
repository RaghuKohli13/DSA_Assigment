#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    bool isMax;
public:
    PriorityQueue(bool type = true) { isMax = type; }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && ((isMax && heap[i] > heap[parent]) || (!isMax && heap[i] < heap[parent]))) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int extreme = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (isMax) {
            if (l < n && heap[l] > heap[extreme]) extreme = l;
            if (r < n && heap[r] > heap[extreme]) extreme = r;
        } else {
            if (l < n && heap[l] < heap[extreme]) extreme = l;
            if (r < n && heap[r] < heap[extreme]) extreme = r;
        }
        if (extreme != i) {
            swap(heap[i], heap[extreme]);
            heapifyDown(extreme);
        }
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteTop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(true);
    int choice, val;
    while (true) {
        cout << "\n1.Insert\n2.Delete Top\n3.Get Top\n4.Display\n5.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; pq.insert(val); break;
            case 2: pq.deleteTop(); break;
            case 3: cout << "Top element: " << pq.top() << endl; break;
            case 4: pq.display(); break;
            case 5: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
