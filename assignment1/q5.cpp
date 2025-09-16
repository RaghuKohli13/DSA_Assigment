#include <iostream> 
using namespace std; 
 int main() { 
    int rows, cols; 
    cout << "Enter number of rows and columns: "; 
    cin >> rows >> cols; 
 
    int arr[100][100]; 
 
    cout << "Enter elements of the matrix:\n"; 
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            cin >> arr[i][j]; 
 
    cout << "Sum of each row:\n"; 
    for (int i = 0; i < rows; ++i) { 
        int rowSum = 0; 
        for (int j = 0; j < cols; ++j) 
            rowSum += arr[i][j]; 
        cout << "Row " << i + 1 << ": " << rowSum << endl; 
    } 
 
    cout << "Sum of each column:\n"; 
    for (int j = 0; j < cols; ++j) { 
        int colSum = 0; 
        for (int i = 0; i < rows; ++i) 
            colSum += arr[i][j]; 
        cout << "Column " << j + 1 << ": " << colSum << endl; 
    } 
 
return 0;
