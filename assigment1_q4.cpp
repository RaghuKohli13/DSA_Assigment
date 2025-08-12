//Q4(A)
#include <iostream> //reverse an array
using namespace std; 
int main(){ 
    int arr[6]={1,2,3,4,5,6}; 
    int size= sizeof(arr)/sizeof(arr[0]); 
    int low=0; 
    int temp; 
    int high=size-1; 
    while(low<high){ 
        temp=arr[high]; 
        arr[high]=arr[low]; 
        arr[low]=temp; 
        low++; 
        high--; 
        temp=0; 
    } 
    for(int i=0 ; i<size; i++){ 
        cout<<arr[i]<<endl; 
    } 
} 

//Q4(B)

#include <iostream> 
using namespace std; 
 int main() { 
    int row1, col1, row2, col2; 
 
    cout << "Enter rows and columns for first matrix: "; 
    cin >> row1 >> col1; 
    cout << "Enter rows and columns for second matrix: "; 
    cin >> row2 >> col2; 
 
    if (col1 != row2) { 
        cout << "Matrix multiplication not possible. Columns of first matrix must equal rows of second.\n";
        return 0; 
    } 
 
    int mat1[100][100], mat2[100][100], result[100][100] = {0}; 
 
    cout << "Enter elements of first matrix:\n"; 
    for (int i = 0; i < row1; ++i) 
        for (int j = 0; j < col1; ++j) 
            cin >> mat1[i][j]; 
 
    cout << "Enter elements of second matrix:\n"; 
    for (int i = 0; i < row2; ++i) 
        for (int j = 0; j < col2; ++j) 
            cin >> mat2[i][j]; 
 
    for (int i = 0; i < row1; ++i) 
        for (int j = 0; j < col2; ++j) 
            for (int k = 0; k < col1; ++k) 
                result[i][j] += mat1[i][k] * mat2[k][j]; 
 
    cout << "Resultant matrix:\n"; 
    for (int i = 0; i < row1; ++i) { 
        for (int j = 0; j < col2; ++j) 
            cout << result[i][j] << " "; 
        cout << endl; 
    } 
 
    return 0; 
}

//Q4(C)

#include <iostream> 
using namespace std;  
int main() { 
    int rows, cols; 
    cout << "Enter number of rows and columns: "; 
    cin >> rows >> cols; 
 
    int matrix[100][100], transpose[100][100]; 
 
    cout << "Enter elements of the matrix:\n"; 
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            cin >> matrix[i][j]; 
 
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            transpose[j][i] = matrix[i][j]; 
 
    cout << "Transpose of the matrix:\n"; 
    for (int i = 0; i < cols; ++i) { 
        for (int j = 0; j < rows; ++j) 
            cout << transpose[i][j] << " "; 
        cout << endl; 
    } 
 
    return 0; 
} 
