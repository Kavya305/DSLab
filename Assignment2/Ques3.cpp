#include <iostream>
using namespace std;

// (a) Linear Time Approach
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; 
        }
    }
    return n;  
}

// (b) Binary Search Approach
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2; 
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1;  
}

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter array elements : "<<endl;
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    
    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}
