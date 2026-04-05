#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream file("myFile.txt");
    string s = "";
    char ch;

    if (!file) {
        cout << "File not found!";
        return 0;
    }

    int lineNo = 1;
    cout << "Line " << lineNo << ": ";

    while (file.get(ch)) {

        bool printed = false;


        if (ch == '"') {
            cout << "STRING, ";
            while (file.get(ch)) {
                if (ch == '"') break;
            }
            printed = true;
        }


        else if (ch == ' ' || ch == '\n' || ch == ';' || ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' || ch == ',' || ch == '+' || ch == '-' ||
                 ch == '=' || ch == '*' || ch == '<') {

            if (s != "") {
                if (s == "int" || s == "float" || s == "return" || s == "if" ||
                    s == "else" || s == "double" || s == "string" || s == "cout") {
                    cout << "KEYWORD, ";
                }
                else if (s[0] >= '0' && s[0] <= '9') {
                    cout << "CONSTANT, ";
                }
                else {
                    cout << "IDENTIFIER, ";
                }
                s = "";
            }

            if (ch == '<') {
                if (file.peek() == '<') {
                    file.get(ch);
                    cout << "OPERATOR, ";
                } else {
                    cout << "OPERATOR, ";
                }
            }

            else if (ch == '+' || ch == '-' || ch == '=' || ch == '*') {
                cout << "OPERATOR, ";
            }

            if (ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ',') {
                cout << "PUNCTUATION, ";
            }

            if (ch == '\n') {
                lineNo++;
                cout << endl << "Line " << lineNo << ": ";
                printed = true;
            }
        }

        else {
            s += ch;
        }
    }

    file.close();
    return 0;
}
