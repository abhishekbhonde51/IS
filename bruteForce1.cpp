#include <iostream>
#include <string>

// Function to generate the next string in sequence
bool nextPassword(std::string &str, const std::string &charset) {
    for (int i = str.size() - 1; i >= 0; --i) {
        auto pos = charset.find(str[i]);
        if (pos != std::string::npos && pos < charset.size() - 1) {
            str[i] = charset[pos + 1];
            return true;
        }
        str[i] = charset[0];
    }
    return false;
}

int main() {
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string target = "abc";  // The password to guess
    std::string guess = "aaa";   // Starting point for guesses

    while (true) {
        if (guess == target) {
            std::cout << "Password found: " << guess << std::endl;
            break;
        }
        if (!nextPassword(guess, charset)) {
            std::cout << "Exhausted all possibilities without finding the password." << std::endl;
            break;
        }
    }

    return 0;
}
