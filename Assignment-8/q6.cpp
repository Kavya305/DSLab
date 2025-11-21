// q6_priority_queue_heaps.cpp
#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int tmp = arr[i]; arr[i] = arr[largest]; arr[largest] = tmp;
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int tmp = arr[i]; arr[i] = arr[smallest]; arr[smallest] = tmp;
        heapifyMin(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i) heapifyMax(arr, n, i);
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i) heapifyMin(arr, n, i);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *base = new int[n];
    for (int i = 0; i < n; ++i) cin >> base[i];

    // Max-priority queue (extract max repeatedly)
    int *arrMax = new int[n];
    for (int i = 0; i < n; ++i) arrMax[i] = base[i];
    buildMaxHeap(arrMax, n);
    cout << "Max-heap extraction order: ";
    int m = n;
    for (int i = n - 1; i >= 0; --i) {
        // root is max
        cout << arrMax[0] << (i ? " " : "");
        // move last to root and heapify reduced heap
        arrMax[0] = arrMax[i];
        heapifyMax(arrMax, i, 0);
    }
    cout << "\n";

    // Min-priority queue (extract min repeatedly)
    int *arrMin = new int[n];
    for (int i = 0; i < n; ++i) arrMin[i] = base[i];
    buildMinHeap(arrMin, n);
    cout << "Min-heap extraction order: ";
    for (int i = n - 1; i >= 0; --i) {
        cout << arrMin[0] << (i ? " " : "");
        arrMin[0] = arrMin[i];
        heapifyMin(arrMin, i, 0);
    }
    cout << "\n";

    delete [] base;
    delete [] arrMax;
    delete [] arrMin;
    return 0;
}
