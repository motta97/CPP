#include<iostream>
#include<string>
using namespace  std;

int string_match(string text, string pattern) {

    int pattern_size = pattern.size();
    int text_size = text.size();
    if (text_size == 0 || pattern_size == 0 || pattern_size<text_size )return false;

    for (int i = 0; i < text_size - pattern_size+1; i++) {
        for (int j = 0; j < pattern_size; j++) {
            if (pattern[j] != text[j+i])break;
            if (j == pattern_size - 1)return i;
        }
    }
    return -1;
}

int main() {
    string text = "My name is Mostafa,I am 32 YO and I live in Cairo";
    string pattern = "MOSTAFA";
    cout << string_match(text, pattern);
}