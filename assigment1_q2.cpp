#include<iostream> 
using namespace std; 
int main(){ 
    int arr[]={2,3,3,4,4,5}; 
    int size=sizeof(arr)/sizeof(arr[0]); 
    int arr1[size];//we are create a new array to store unique elements 
    arr1[0]=arr[0]; 
    int x=0; 
    for(int i=1 ; i<size ; i++){ 
        if(arr1[x]!=arr[i]){ 
            x++; 
            arr1[x]=arr[i]; 
        } 
    } 
    for(int i = 0 ; i<=x ; i++){ 
        cout<<arr1[i]<<" "<<endl;
    }
}