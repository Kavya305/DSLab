#include <iostream>
using namespace std;

/* ========== (a) Diagonal Matrix ========== */
void diagonalMatrix(int n) {
    int *A = new int[n]; // dynamic allocation

    cout<<"\nEnter diagonal elements:\n";
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }

    cout<<"\nDiagonal Matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    delete[] A;
}

/* ========== (b) Tri-diagonal Matrix ========== */
void triDiagonalMatrix(int n) {
    int size = 3*n - 2;
    int *A = new int[size]; 

    cout<<"\nEnter tri-diagonal elements (row-wise full matrix, others ignored):\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x; cin>>x;
            if(i-j==1) A[i-1] = x;          // lower diag
            else if(i-j==0) A[n-1+i] = x;   // main diag
            else if(i-j==-1) A[2*n-1+i] = x;// upper diag
        }
    }

    cout<<"\nTri-diagonal Matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i-j==1) cout<<A[i-1]<<" ";
            else if(i-j==0) cout<<A[n-1+i]<<" ";
            else if(i-j==-1) cout<<A[2*n-1+i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    delete[] A;
}

/* ========== (c) Lower Triangular Matrix ========== */
void lowerTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int *A = new int[size];

    cout<<"\nEnter lower triangular elements row-wise:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            int x; cin>>x;
            A[i*(i+1)/2 + j] = x;
        }
    }

    cout<<"\nLower Triangular Matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i>=j) cout<<A[i*(i+1)/2 + j]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    delete[] A;
}

/* ========== (d) Upper Triangular Matrix ========== */
void upperTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int *A = new int[size];

    cout<<"\nEnter upper triangular elements row-wise:\n";
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int x; cin>>x;
            A[n*i - (i*(i-1))/2 + (j-i)] = x;
        }
    }

    cout<<"\nUpper Triangular Matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<=j) cout<<A[n*i - (i*(i-1))/2 + (j-i)]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    delete[] A;
}

/* ========== (e) Symmetric Matrix ========== */
void symmetricMatrix(int n) {
    int size = n*(n+1)/2;
    int *A = new int[size];

    cout<<"\nEnter symmetric matrix (lower half only, row-wise):\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            int x; cin>>x;
            A[i*(i+1)/2 + j] = x;
        }
    }

    cout<<"\nSymmetric Matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i>=j) cout<<A[i*(i+1)/2 + j]<<" ";
            else cout<<A[j*(j+1)/2 + i]<<" ";
        }
        cout<<endl;
    }
    delete[] A;
}

/* ========== MAIN ========== */
int main() {
    int n;
    cout<<"Enter size of matrix (n): ";
    cin>>n;

    diagonalMatrix(n);
    triDiagonalMatrix(n);
    lowerTriangularMatrix(n);
    upperTriangularMatrix(n);
    symmetricMatrix(n);

    return 0;
}
