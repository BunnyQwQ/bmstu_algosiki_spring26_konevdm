#include <iostream>
#include <stack>
using namespace std;


void sortStack(stack<int>& mainStack) {
    stack<int> helperStack;
    int temp;

    while (!mainStack.empty()) {
        temp = mainStack.top();
        mainStack.pop();

        while (!helperStack.empty() && helperStack.top() > temp) {
            mainStack.push(helperStack.top());
            helperStack.pop();
        }

        helperStack.push(temp);
    }

    while (!helperStack.empty()) {
        mainStack.push(helperStack.top());
        helperStack.pop();
    }
}


void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {

    stack<int> S;

    S.push(5);
    S.push(2);
    S.push(8);
    S.push(1);
    S.push(9);
    S.push(3);

    cout << "Stack: ";
    printStack(S);

    sortStack(S);

    cout << "Sorted Stack: ";
    printStack(S);

    return 0;
}
