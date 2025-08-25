#include<iostream>
#include<algorithm>
using namespace std;

// 1. Binary Search Algorithm
int binarySearch(int arr[], int n, int key){
    sort(arr,arr+n);
    cout<<"Sorted Array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int arr[] = {13,42,62,42,67,12};
    int n = sizeof(arr)/sizeof(int);
    int key = 42;
    int result = binarySearch(arr,n,key);
    if(result == -1){
        cout<<"Element not found!"<<endl;
    } else{
        cout<<"Element found at index : "<<result<<endl;
    }

    return 0;
}
