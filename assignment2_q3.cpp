#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    return n;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = 6; // range is 1 to 6
    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    return 0;
}
