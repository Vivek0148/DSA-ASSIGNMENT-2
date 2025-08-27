#include <iostream>
using namespace std;
void transpose(int sparse[20][3], int t[20][3]) {
    int i, j, k;
    int rows = sparse[0][0], cols = sparse[0][1], terms = sparse[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = terms;
    k = 1;
    for (i = 0; i < cols; i++) {
        for (j = 1; j <= terms; j++) {
            if (sparse[j][1] == i) {
                t[k][0] = sparse[j][1];
                t[k][1] = sparse[j][0];
                t[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}
int main() {
    int sparse[20][3] = {{3, 3, 3}, {0, 0, 5}, {1, 1, 8}, {2, 2, 10}};
    int t[20][3];
    transpose(sparse, t);
    cout << "Transpose in Triplet form:\n";
    for (int i = 0; i <= t[0][2]; i++)
        cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << endl;
    return 0;
}
