// q5_heapsort.cpp
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool isMaxHeap) {
    int extreme = i; // index of max (for max-heap) or min (for min-heap)
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (isMaxHeap) {
        if (l < n && arr[l] > arr[extreme]) extreme = l;
        if (r < n && arr[r] > arr[extreme]) extreme = r;
    } else {
        if (l < n && arr[l] < arr[extreme]) extreme = l;
        if (r < n && arr[r] < arr[extreme]) extreme = r;
    }

    if (extreme != i) {
        int tmp = arr[i]; arr[i] = arr[extreme]; arr[extreme] = tmp;
        heapify(arr, n, extreme, isMaxHeap);
    }
}

void buildHeap(int arr[], int n, bool isMaxHeap) {
    for (int i = n/2 - 1; i >= 0; --i) heapify(arr, n, i, isMaxHeap);
}

void heapSort(int arr[], int n, bool ascending) {
    // For ascending result, build a max-heap and repeatedly extract max.
    // For descending result, build a min-heap and repeatedly extract min.
    bool isMaxHeap = ascending;
    buildHeap(arr, n, isMaxHeap);
    for (int i = n - 1; i >= 1; --i) {
        int tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        heapify(arr, i, 0, isMaxHeap);
    }
    // If we built min-heap for descending, result is descending after this process.
    // If we built max-heap for ascending, result is ascending.
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int choice;
    cin >> choice; // 1 => increasing (ascending), 2 => decreasing (descending)

    if (choice == 1) heapSort(arr, n, true);
    else heapSort(arr, n, false);

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << "\n";

    delete [] arr;
    return 0;
}
