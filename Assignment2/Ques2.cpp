#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        for(int j = 0; j <= n-i-1; j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}