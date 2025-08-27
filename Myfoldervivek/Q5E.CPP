#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    int A[n*(n+1)/2] = {0};
    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
        }
    }
    cout << "\nSymmetric Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) cout << A[i*(i-1)/2 + (j-1)] << " ";
            else cout << A[j*(j-1)/2 + (i-1)] << " ";
        }
        cout << endl;
    }
    return 0;
}
