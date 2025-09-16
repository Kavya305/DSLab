#include <iostream>
using namespace std;

#define MAX 100

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, nonZero;
    Element data[MAX];
};

void readMatrix(SparseMatrix &s) {
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> s.rows;
    cin>> s.cols;
    cin>> s.nonZero;

    cout << "Enter row, col and value of each element: "<<endl;
    for (int i = 0; i < s.nonZero; i++) {
        cin >> s.data[i].row;
        cin >> s.data[i].col;
        cin >> s.data[i].val;
    }
}


void printMatrix(SparseMatrix &s) {
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i < s.nonZero; i++) {
        cout << s.data[i].row << "\t" << s.data[i].col << "\t" << s.data[i].val << "\n";
    }
}

// (a) Transpose
SparseMatrix transpose(SparseMatrix &s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.nonZero = s.nonZero;

    for (int i = 0; i < s.nonZero; i++) {
        t.data[i].row = s.data[i].col;
        t.data[i].col = s.data[i].row;
        t.data[i].val = s.data[i].val;
    }
    return t;
}

// (b) Addition
SparseMatrix add(SparseMatrix &a, SparseMatrix &b) {
    SparseMatrix sum;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible!"<<endl;
        sum.nonZero = 0;
        return sum;
    }

    sum.rows = a.rows;
    sum.cols = a.cols;
    sum.nonZero = 0;

    int i = 0, j = 0;
    while (i < a.nonZero && j < b.nonZero) {
        if (a.data[i].row < b.data[j].row ||
           (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[sum.nonZero] = a.data[i];
            sum.nonZero++;
            i++;
        } else if (b.data[j].row < a.data[i].row ||
                  (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            sum.data[sum.nonZero] = b.data[j];
            sum.nonZero++;
            j++;
        } else {
            Element temp = a.data[i];
            temp.val += b.data[j].val;
            if (temp.val != 0)
                sum.data[sum.nonZero] = temp;
            sum.nonZero++
            i++;
            j++;
        }
    }

    while (i < a.nonZero){
        sum.data[sum.nonZero] = a.data[i];
        sum.nonZero++;
        i++;
    }
    while (j < b.nonZero){
        sum.data[sum.nonZero] = b.data[j];
        sum.nonZero++;
        j++;
    }

    return sum;
}

//Multiplication
SparseMatrix multiply(SparseMatrix &a, SparseMatrix &b) {
    SparseMatrix product;
    if (a.cols != b.rows) {
        cout << "Multiplication not possible!\n";
        product.nonZero = 0;
        return product;
    }

    product.rows = a.rows;
    product.cols = b.cols;
    product.nonZero = 0;

    for (int i = 0; i < a.nonZero; i++) {
        for (int j = 0; j < b.nonZero; j++) {
            if (a.data[i].col == b.data[j].row) {
                int r = a.data[i].row;
                int c = b.data[j].col;
                int v = a.data[i].val * b.data[j].val;

                bool found = false;
                for (int k = 0; k < product.nonZero; k++) {
                    if (product.data[k].row == r && product.data[k].col == c) {
                        product.data[k].val += v;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    product.data[product.nonZero].row = r;
                    product.data[product.nonZero].col = c;
                    product.data[product.nonZero].val = v;
                    product.nonZero++;
                }
            }
        }
    }

    return product;
}

int main() {
    SparseMatrix A, B;

    cout << "Enter first matrix:\n";
    readMatrix(A);
    cout << "Enter second matrix:\n";
    readMatrix(B);

    cout << "\nMatrix A:\n"; printMatrix(A);
    cout << "\nMatrix B:\n"; printMatrix(B);

    cout << "\nTranspose of A:\n"; printMatrix(transpose(A));

    cout << "\nAddition (A + B):\n"; printMatrix(add(A, B));

    cout << "\nMultiplication (A * B):\n"; printMatrix(multiply(A, B));

    return 0;
}

