#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i] > A[j]) {
                count++;
                cout << "Inversion: ("<< A[i] << ", " << A[j] <<")"<<endl;
            }
        }
    }

    cout << "Total number of inversions = " << count << endl;

    return 0;
}

