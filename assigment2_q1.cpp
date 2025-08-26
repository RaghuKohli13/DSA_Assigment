#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            left = mid + 1; 
        else
            right = mid - 1; 
    }
    return -1; 
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i; 
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int binaryIndex = binarySearch(arr, size, target);
    if (binaryIndex != -1)
        cout << "Binary Search: Found at index " << binaryIndex << endl;
    else
        cout << "Binary Search: Not found" << endl;

    int linearIndex = linearSearch(arr, size, target);
    if (linearIndex != -1)
        cout << "Linear Search: Found at index " << linearIndex << endl;
    else
        cout << "Linear Search: Not found" << endl;

    return 0;
}
