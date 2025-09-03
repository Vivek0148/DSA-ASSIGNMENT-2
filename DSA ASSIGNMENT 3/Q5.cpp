#include <iostream>   
#include <stack>      
#include <cctype>     
using namespace std;
int main() {
    string postfix;    
    stack<int> st;     
    cout << "Enter postfix expression: ";
    cin >> postfix;    
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];   
        if (isdigit(ch)) {
            st.push(ch - '0'); 
        }
        else {
            int val2 = st.top(); st.pop(); 
            int val1 = st.top(); st.pop();  
            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    cout << "Result:" << st.top() << endl;
    return 0;
}
