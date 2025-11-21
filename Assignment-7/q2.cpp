#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Ensure initial order is correct
        if (arr[minIndex] > arr[maxIndex]) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[maxIndex];
            arr[maxIndex] = temp;
        }

        // Find actual min and max in the remaining part
        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            else if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place the minimum at left
        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        // If max was at left location and we swapped it,
        // update maxIndex
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place the maximum at right
        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
