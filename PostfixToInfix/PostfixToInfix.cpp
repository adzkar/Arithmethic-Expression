#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeWS(string var) {
    string temp;
    for(int i = 0;i < var.length();i++)
        if(var[i] != ' ') temp.push_back(var[i]);
    return temp;
}

string ctos(char a) {
    int b = (int) a;
    string c;
    return c = (char) b;
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
    stack<string> output;
    string temp, result;
    for(int i = 0;i < var.length();i++) {
        if(var[i] != '+' && var[i] != '-' && var[i] != '/' && var[i] != '*') output.push(ctos(var[i]));
        else {
            temp = output.top();
            output.pop();
            result = output.top() + var[i] + temp;
            output.pop();
            output.push(result);
        }
    }

    cout << output.top() << endl;

}


int main() {

    string input;
    cout << "[Input] > ";
    while((getline(cin, input)) && (input != "exit")) {
        converter(input);
        cout << "[Input] > ";
    }

    return 0;
}