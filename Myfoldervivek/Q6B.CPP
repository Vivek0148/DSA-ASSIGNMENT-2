#include <iostream>
using namespace std;
void addSparse(int A[20][3], int B[20][3], int C[40][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added\n";
        return;
    }
    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        } 
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        } 
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }
    while (i <= A[0][2]) { C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++; }
    while (j <= B[0][2]) { C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++; }
    C[0][2] = k - 1;
    cout << "\nResultant Sparse Matrix:\n";
    for (int p = 0; p <= C[0][2]; p++)
        cout << C[p][0] << " " << C[p][1] << " " << C[p][2] << endl;
}
int main() {
    int A[20][3] = {{3, 3, 2}, {0, 0, 5}, {1, 2, 8}};
    int B[20][3] = {{3, 3, 2}, {0, 0, 3}, {2, 1, 6}};
    int C[40][3];
    addSparse(A, B, C);
    return 0;
}
