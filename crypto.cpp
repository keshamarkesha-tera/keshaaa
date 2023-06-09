#include <iostream>
#include <string>
using namespace std;

string Vigenere(const string& message, const string& key) {
    string encryptedMessage = "";
    int messageLen = message.length();
    int keyLen = key.length();
    for (int i = 0; i < messageLen; i++) {
        char currentChar = message[i];
        char keyChar = key[i % keyLen];
        if (isalpha(currentChar)) {
            if (isupper(currentChar)) {
                currentChar = toupper(currentChar);
                keyChar = toupper(keyChar);
                char encryptedChar = ((currentChar - 'A') + (keyChar - 'A')) % 26 + 'A';
                encryptedMessage += encryptedChar;
            }
            else if (islower(currentChar)) {
                currentChar = tolower(currentChar);
                keyChar = tolower(keyChar);
                char encryptedChar = ((currentChar - 'a') + (keyChar - 'a')) % 26 + 'a';
                encryptedMessage += encryptedChar;
            }
        }
        else {
            encryptedMessage += currentChar;
        }
    }
    return encryptedMessage;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string decryptVigenere(const string& encryptedMessage, const string& key) {
    string decryptedMessage = "";
    int messageLen = encryptedMessage.length();
    int keyLen = key.length();
    for (int i = 0; i < messageLen; i++) {
        char currentChar = encryptedMessage[i];
        char keyChar = key[i % keyLen];
        if (isalpha(currentChar)) {
            if (isupper(currentChar)) {
                currentChar = toupper(currentChar);
                keyChar = toupper(keyChar);
                char decryptedChar = ((currentChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';
                decryptedMessage += decryptedChar;
            }
            else if (islower(currentChar)) {
                currentChar = tolower(currentChar);
                keyChar = tolower(keyChar);
                char decryptedChar = ((currentChar - 'a') - (keyChar - 'a') + 26) % 26 + 'a';
                decryptedMessage += decryptedChar;
            }
        }
        else {
            decryptedMessage += currentChar;
        }
    }
    return decryptedMessage;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int amoba() {
    string message, key;

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter the key: ";
    getline(cin, key);

    string encryptedMessage = Vigenere(message, key);
    cout << "Encrypted message: " << encryptedMessage << endl;

    string decryptedMessage = Vigenere(encryptedMessage, key);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}