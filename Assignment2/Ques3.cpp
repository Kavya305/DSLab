#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int st = 0, end = n - 1;
    int diff = arr[0]-0;  

    while (st <= end) {
        int mid = (st + end) / 2;

        if ((arr[mid] - mid) == diff) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return st + diff; 
}

int main() {
    int arr[] = {1, 2, 3, 5};  // 4 is missing
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number is: " << findMissingNumber(arr, n) << endl;
    return 0;
}
