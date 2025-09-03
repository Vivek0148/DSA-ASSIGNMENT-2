#include <iostream>
using namespace std;
int main() {
    char s[100];
    int i, c= 0;
    cout << "Enter an expression";
    cin>>s;
    for (i =0;s[i]!='\0';i++) {
        if (s[i] =='(')
            c++;
        else if (s[i]== ')')
            c--;
        if (c < 0) { 
            cout <<"Not Balanced";
            return 0;
        }
    }
    if (c==0)
        cout <<"Balanced";
    else
        cout <<"Not Balanced";
    return 0;
}
