#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    string pancake, donut = "";
    stack<char> fridge;
    cout << "Enter infix expression";
    cin >> pancake;
    for (int banana=0; banana<pancake.length();banana++) {
        char cookie= pancake[banana];
        if (isalnum(cookie)) {
            donut += cookie;
        }
        else if (cookie == '(') {
            fridge.push(cookie);
        }
        else if (cookie == ')') {
            while (!fridge.empty() && fridge.top() != '(') {
                donut += fridge.top();
                fridge.pop();
            }
            fridge.pop();
        }
        else {
            int pizza;
            if (cookie == '+' || cookie == '-') pizza = 1;
            else if (cookie == '*' || cookie == '/') pizza = 2;
            else if (cookie == '^') pizza = 3;
            else pizza = 0;

            while (!fridge.empty()) {
                int burger;
                if (fridge.top() == '+' || fridge.top() == '-') burger = 1;
                else if (fridge.top() == '*' || fridge.top() == '/') burger = 2;
                else if (fridge.top() == '^') burger = 3;
                else burger = 0;

                if (burger >= pizza) {
                    donut += fridge.top();
                    fridge.pop();
                } else break;
            }
            fridge.push(cookie);
        }
    }

    while (!fridge.empty()) {
        donut += fridge.top();
        fridge.pop();
    }

    cout << "Postfix expression: " << donut << endl;
    return 0;
}

