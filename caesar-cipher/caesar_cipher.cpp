#include <iostream>
#include <string>
using namespace std;

// Encrypts or decrypts text using a Caesar cipher shift.
// here we use mode = 1 for encrypt and mode = -1 for decrypt (same logic opposite direction)
string caesarShift(const string &text, int key, int mode) {
    string result = "";
    key = ((key % 26) + 26) % 26; // make key from 0 to 25

    for (char ch : text) {
        if (isupper(ch)) {
            result += char(((ch - 'A' + mode * key + 26) % 26) + 'A');
        } else if (islower(ch)) {
            result += char(((ch - 'a' + mode * key + 26) % 26) + 'a');
        } else {
            result += ch; 
        }
    }
    return result;
}

void encryptDecrypt() {
    string text;
    int key;
    int choice;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key (0-25): ";
    cin >> key;
    cout << "1. Encrypt\n2. Decrypt\nChoice: ";
    cin >> choice;
    int mode = (choice == 1) ? 1 : -1;
    string output = caesarShift(text, key, mode);
    cout << "Result: " << output << endl;
}

void bruteForceCrack() {
    string cipherText;
    cout << "Enter ciphertext to crack: ";
    cin.ignore();
    getline(cin, cipherText);
    cout << "\nTrying all 26 possible shifts:\n";
    cout << "----------------------------------\n";
    for (int key = 0; key < 26; key++) {
        string attempt = caesarShift(cipherText, key, -1);
        cout << "Key " << key << ": " << attempt << endl;
    }
    cout << "----------------------------------\n";
    cout << "Look for the line that reads as valid English text.\n";
}

int main() {
    int choice;
    cout << "=== Caesar Cipher Tool ===\n";
    cout << "1. Encrypt/Decrypt (I know the key)\n";
    cout << "2. Brute Force Crack (I don't know the key)\n";
    cout << "Choice: ";
    cin >> choice;
    if (choice == 1) {
        cin.ignore();
        encryptDecrypt();
    } else if (choice == 2) {
        bruteForceCrack();
    } else {
        cout << "Invalid choice.\n";
    }
    return 0;
}
