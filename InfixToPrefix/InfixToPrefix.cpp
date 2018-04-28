#include <iostream>
#include <stack>

using namespace std;

string removeWS(string var) {
    string temp;
    for(int i = 0;i < var.length();i++)
        if(var[i] != ' ') temp.push_back(var[i]);
    return temp;
}

string reverse(string var) {
    string temp;
    var = removeWS(var);
    for(int i = var.length()-1;i < var.length();i--)
        temp.push_back(var[i]);
    return temp;
}

int operatorLevel(char a) {
    switch(a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}

void converter(string var) {
    stack<char> output;
    stack<char> stack;
    var = reverse(removeWS(var));
    for(int i = 0;i < var.length();i++) {
        if(var[i] != '+' && var[i] != '-' && var[i] != '*' && var[i] != '/') output.push(var[i]);
        else {
            if(stack.empty()) stack.push(var[i]);
            else {
                if(operatorLevel(var[i]) >= operatorLevel(stack.top())) stack.push(var[i]);
                while(!stack.empty() && operatorLevel(var[i]) < operatorLevel(stack.top())) {
                    output.push(stack.top());
                    stack.pop();
                    stack.push(var[i]);
                }
            }
        }
    }
    
    while(!stack.empty()) {
        output.push(stack.top());
        stack.pop();
    }

    // output hasil
    while(!output.empty()){
        cout << output.top();
        output.pop();
    }
    cout << endl;
}

int main() {

    string input;
    cout << "[Input] > ";
    while(getline(cin, input) && (input != "exit")) {
        converter(input);
        cout << "[Input] > ";
    }


    return 0;
}
