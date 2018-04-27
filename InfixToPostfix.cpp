#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string removeWS(string var) {
    string temp;
    for(int i = 0;i < var.length();i++)
        if(var[i] != ' ') temp.push_back(var[i]);
    return temp;
}

bool isValid(string var) {
    bool a = 1;
    for(int i = 0;i < var.length();i++) 
        if(var[i] >= 'a') a = 0;    
    return a;
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
    var = removeWS(var);
    vector<char> output;
    stack<char> stack;
    for(int i = 0;i < var.length();i++) {
        if(var[i] != '+' && var[i] != '-' && var[i] != '*' && var[i] != '/' && var[i] != '^') output.push_back(var[i]);
        else {
            if(stack.empty()) stack.push(var[i]);
            else {
                while(!stack.empty() && operatorLevel(var[i]) <= operatorLevel(stack.top())) {
                    output.push_back(stack.top());
                    stack.pop();
                }
                stack.push(var[i]);
            }
        }
    }
    while(!stack.empty()) {
        output.push_back(stack.top());
        stack.pop();
    }
    for(int i = 0;i < var.length();i++) cout << output[i] << " ";
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