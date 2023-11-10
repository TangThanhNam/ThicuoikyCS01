#include <iostream>
#include <string>
using namespace std;

string encodeString(const string &s) {
    string encoded = "";
    int count = 1;

    for (size_t i = 1; i <= s.length(); ++i) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            encoded += s[i - 1];
            if (count > 1) encoded += to_string(count);
            count = 1;
        }
    }

    return encoded;
}

int main() {
    string input;
    cout << "Enter the string to encode: ";
    getline(cin, input);
    cout << "Encoded string: " << encodeString(input) << endl;
    return 0;
}
