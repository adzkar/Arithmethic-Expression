#include <iostream>
#include <stack>
#include <string>

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

string ctos(char a) {
    int b = (int) a;
    string c;
    return c = (char) b;
}

void converter(string var) {
    stack<string> output;
    var = reverse(removeWS(var));
    string result, temp;
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

    cout << reverse(output.top()) << endl;
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