#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices A and B
void multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    // Base case: if matrix is of size 1x1, multiply directly
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide the matrix into 4 submatrices
    int newSize = n / 2;

    // Create submatrices for A, B and C
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));

    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    // Split matrix A into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
        }
    }

    // Split matrix B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Create intermediate result matrices
    vector<vector<int>> C11(newSize, vector<int>(newSize));
    vector<vector<int>> C12(newSize, vector<int>(newSize));
    vector<vector<int>> C21(newSize, vector<int>(newSize));
    vector<vector<int>> C22(newSize, vector<int>(newSize));

    // Recursive calls for matrix multiplication
    vector<vector<int>> temp(newSize, vector<int>(newSize));

    // C11 = A11 * B11 + A12 * B21
    multiplyMatrix(A11, B11, C11, newSize);
    multiplyMatrix(A12, B21, temp, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C11[i][j] += temp[i][j];
        }
    }

    // C12 = A11 * B12 + A12 * B22
    multiplyMatrix(A11, B12, C12, newSize);
    multiplyMatrix(A12, B22, temp, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C12[i][j] += temp[i][j];
        }
    }

    // C21 = A21 * B11 + A22 * B21
    multiplyMatrix(A21, B11, C21, newSize);
    multiplyMatrix(A22, B21, temp, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C21[i][j] += temp[i][j];
        }
    }

    // C22 = A21 * B12 + A22 * B22
    multiplyMatrix(A21, B12, C22, newSize);
    multiplyMatrix(A22, B22, temp, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C22[i][j] += temp[i][j];
        }
    }

    // Combine submatrices into final result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the matrices (must be a power of 2): ";
    cin >> size;

    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    vector<vector<int>> C(size, vector<int>(size));

    cout << "Enter matrix A elements: \n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B elements: \n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> B[i][j];
        }
    }

    // Perform matrix multiplication
    multiplyMatrix(A, B, C, size);

    cout << "Resulting matrix C (A * B): \n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
