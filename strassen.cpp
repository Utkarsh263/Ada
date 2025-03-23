#include <iostream>
#include <vector>

using namespace std;

void addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's matrix multiplication
void strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));

    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    vector<vector<int>> M1(newSize, vector<int>(newSize));
    vector<vector<int>> M2(newSize, vector<int>(newSize));
    vector<vector<int>> M3(newSize, vector<int>(newSize));
    vector<vector<int>> M4(newSize, vector<int>(newSize));
    vector<vector<int>> M5(newSize, vector<int>(newSize));
    vector<vector<int>> M6(newSize, vector<int>(newSize));
    vector<vector<int>> M7(newSize, vector<int>(newSize));

    vector<vector<int>> temp1(newSize, vector<int>(newSize));
    vector<vector<int>> temp2(newSize, vector<int>(newSize));

    // Divide A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M1, newSize);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, temp1, newSize);
    strassenMultiply(temp1, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, temp2, newSize);
    strassenMultiply(A11, temp2, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, temp2, newSize);
    strassenMultiply(A22, temp2, M4, newSize);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, temp1, newSize);
    strassenMultiply(temp1, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassenMultiply(temp1, temp2, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, temp1, newSize);
    subtractMatrix(M5, M7, temp2, newSize);
    addMatrix(temp1, temp2, C, newSize);

    // C12 = M3 + M5
    addMatrix(M3, M5, temp1, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j + newSize] = temp1[i][j];
        }
    }

    // C21 = M2 + M4
    addMatrix(M2, M4, temp1, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i + newSize][j] = temp1[i][j];
        }
    }

    // C22 = M1 - M2 + M3 + M6
    addMatrix(M1, M3, temp1, newSize);
    subtractMatrix(M2, M6, temp2, newSize);
    addMatrix(temp1, temp2, temp1, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i + newSize][j + newSize] = temp1[i][j];
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the matrix (should be a power of 2): ";
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

    strassenMultiply(A, B, C, size);

    cout << "Result matrix C (A * B): \n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
