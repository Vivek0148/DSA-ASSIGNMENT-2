#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++){
         cin >> A[i];
    }
    int distinct = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            distinct++;
        }
    }
    cout << "Total distinct elements = " << distinct << endl;
    return 0;
}
