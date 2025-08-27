#include <iostream>
using namespace std;
void multiply(int A[20][3], int B[20][3], int C[40][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix multiplication not possible\n";
        return;
    }
    int rowA = A[0][0], colB = B[0][1];
    int termsA = A[0][2], termsB = B[0][2];
    int k = 1;
    C[0][0] = rowA;
    C[0][1] = colB;
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            int sum = 0;
            for (int p = 1; p <= termsA; p++) {
                if (A[p][0] == i) {
                    for (int q = 1; q <= termsB; q++) {
                        if (B[q][1] == j && B[q][0] == A[p][1]) {
                            sum += A[p][2] * B[q][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = sum;
                k++;
            }
        }
    }
    C[0][2] = k - 1;
    cout << "\nResultant Multiplication Matrix:\n";
    for (int i = 0; i <= C[0][2]; i++)
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
}
int main() {
    int A[20][3] = {{2, 3, 2}, {0, 0, 2}, {1, 2, 3}};
    int B[20][3] = {{3, 2, 2}, {0, 1, 4}, {2, 0, 5}};
    int C[40][3];
    multiply(A, B, C);
    return 0;
}
