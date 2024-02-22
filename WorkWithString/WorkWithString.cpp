#include <iostream>
#include <string> 
using namespace std;

//В строке текста записаны слова, разделенные пробелами в произвольном количестве. Сжатие текста состоит 
//в том, что между словами оставляется по одному пробелу, а после последнего слова пробелы удаляются(пробелы
//перед первым словом сохраняются).Если строка содержит только пробелы, то все они сохраняются.
//Написать функцию, сжимающую описанным образом текст.

void compressText(const string& input) {
    string compressedText;
    bool isFirstWord = true;

    for (char c : input) {

        if (isalpha(c) || ispunct(c) || isdigit(c)) {

            compressedText.push_back(c);
            isFirstWord = false;
        }
        else if (c == ' ' && !isFirstWord) {
            compressedText.push_back(c);
            isFirstWord = true;
        }
    }
    cout << "Text: " << compressedText;
}

bool nonAlphaNum(const string& str) {
    for (char c : str) {

        if (!isalnum(c) && !isspace(c) && !ispunct(c)) {
            return true;
        }
    }
    return false;
}

int main() {
    string inputText;

    cout << "Enter text: ";
    getline(cin, inputText);

    if (!nonAlphaNum(inputText)) {
        cout << "Text: " << inputText;
    }
    else {
        compressText(inputText);
    }

    return 0;
}




