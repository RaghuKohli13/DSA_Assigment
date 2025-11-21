#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing) {
    int extreme = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (increasing) {
        if (l < n && arr[l] > arr[extreme]) extreme = l;
        if (r < n && arr[r] > arr[extreme]) extreme = r;
    } else {
        if (l < n && arr[l] < arr[extreme]) extreme = l;
        if (r < n && arr[r] < arr[extreme]) extreme = r;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "1. Increasing Order\n2. Decreasing Order\nEnter choice: ";
    int ch;
    cin >> ch;

    heapSort(arr, n, ch == 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
