#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

// Define token types
enum Token {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,  // Left Parenthesis
    TOKEN_RPAREN,  // Right Parenthesis
    TOKEN_EOF,     // End of File
    TOKEN_INVALID  // Invalid Token
};

// Token structure
struct TokenData {
    Token type;
    string value;
};

// Function to tokenize input
vector<TokenData> lexicalAnalysis(const string& input) {
    vector<TokenData> tokens;
    size_t i = 0;
    size_t len = input.length();

    while (i < len) {
        char currentChar = input[i];

        // Skip whitespaces
        if (isspace(currentChar)) {
            i++;
            continue;
        }

        // Check for numbers
        if (isdigit(currentChar)) {
            string numberValue = "";
            while (i < len && isdigit(input[i])) {
                numberValue += input[i];
                i++;
            }
            tokens.push_back({TOKEN_NUMBER, numberValue});
        }
        // Check for operators and parentheses
        else if (currentChar == '+') {
            tokens.push_back({TOKEN_PLUS, "+"});
            i++;
        } else if (currentChar == '-') {
            tokens.push_back({TOKEN_MINUS, "-"});
            i++;
        } else if (currentChar == '*') {
            tokens.push_back({TOKEN_MULTIPLY, "*"});
            i++;
        } else if (currentChar == '/') {
            tokens.push_back({TOKEN_DIVIDE, "/"});
            i++;
        } else if (currentChar == '(') {
            tokens.push_back({TOKEN_LPAREN, "("});
            i++;
        } else if (currentChar == ')') {
            tokens.push_back({TOKEN_RPAREN, ")"});
            i++;
        }
        // Invalid character
        else {
            tokens.push_back({TOKEN_INVALID, string(1, currentChar)});
            i++;
        }
    }

    // Add EOF token to indicate the end
    tokens.push_back({TOKEN_EOF, "EOF"});
    return tokens;
}

// Function to display tokens
void displayTokens(const vector<TokenData>& tokens) {
    for (const auto& token : tokens) {
        switch (token.type) {
            case TOKEN_NUMBER:
                cout << "NUMBER: " << token.value << endl;
                break;
            case TOKEN_PLUS:
                cout << "PLUS: " << token.value << endl;
                break;
            case TOKEN_MINUS:
                cout << "MINUS: " << token.value << endl;
                break;
            case TOKEN_MULTIPLY:
                cout << "MULTIPLY: " << token.value << endl;
                break;
            case TOKEN_DIVIDE:
                cout << "DIVIDE: " << token.value << endl;
                break;
            case TOKEN_LPAREN:
                cout << "LPAREN: " << token.value << endl;
                break;
            case TOKEN_RPAREN:
                cout << "RPAREN: " << token.value << endl;
                break;
            case TOKEN_EOF:
                cout << "EOF" << endl;
                break;
            case TOKEN_INVALID:
                cout << "INVALID: " << token.value << endl;
                break;
        }
    }
}

int main() {
    // Input string for lexical analysis
    string input;
    cout << "Enter the expression for lexical analysis: ";
    getline(cin, input);

    // Perform lexical analysis
    vector<TokenData> tokens = lexicalAnalysis(input);

    // Display the tokens
    displayTokens(tokens);

    return 0;
}

