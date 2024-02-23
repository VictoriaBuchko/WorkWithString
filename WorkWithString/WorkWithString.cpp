#include <iostream>
#include <string>

using namespace std;

void compressText(const string& input) {
    string compressedText;
    bool isFirstSpace = true;

    for (char c : input) {
        if (isalpha(c) || ispunct(c) || isdigit(c)) {
            compressedText.push_back(c);
            isFirstSpace = false;
        }
        else if (c == ' ' && isFirstSpace) {
            compressedText.push_back(c);
        }
        else if (c == ' ' && !isFirstSpace) {
            if (!isspace(compressedText.back())) {
                compressedText.push_back(c);
            }
        }
    }
    cout << "Text: " << compressedText;
}

int main() {
    string inputText;

    cout << "Enter text: ";
    getline(cin, inputText);

    bool isOnlySpaces = true;
    for (char c : inputText) {
        if (!isspace(c)) {
            isOnlySpaces = false;
            break;
        }
    }

    if (isOnlySpaces) {
        cout << "Text: " << inputText;
    }
    else {
        compressText(inputText);
    }

    return 0;
}





