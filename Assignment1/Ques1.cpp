#include <iostream>
using namespace std;

#define MAX 100

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Max size exceeded! Setting size to " << MAX << endl;
        n = MAX;
    }
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    int pos, val;
    cout << "Enter position (0-based index): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    if (n >= MAX) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted.\n";
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position (0-based index) to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int arr[MAX], n = 0, choice;

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) createArray(arr, n);
        else if (choice == 2) displayArray(arr, n);
        else if (choice == 3) insertElement(arr, n);
        else if (choice == 4) deleteElement(arr, n);
        else if (choice == 5) linearSearch(arr, n);
        else if (choice == 6) break;
        else cout << "Invalid choice!\n";
    }

    return 0;
}
