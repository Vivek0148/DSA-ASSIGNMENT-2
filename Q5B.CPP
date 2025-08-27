#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    int A[3*n - 2] = {0};
    cout << "Enter elements of tri-diagonal matrix row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (i - j == 1) A[i-1] = x;
            else if (i - j == 0) A[n-1+i-1] = x;
            else if (j - i == 1) A[2*n-1+i-1] = x;
        }
    }
    cout << "\nTri-diagonal Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j == 1) cout << A[i-1] << " ";
            else if (i - j == 0) cout << A[n-1+i-1] << " ";
            else if (j - i == 1) cout << A[2*n-1+i-1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
