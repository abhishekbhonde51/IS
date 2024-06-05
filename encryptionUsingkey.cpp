#include <iostream>
#include <string>

// Function to encrypt a message using the Caesar cipher and a given key
std::string encrypt(const std::string& message, int key) {
    std::string encrypted = "";
    for (char c : message) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            encrypted += static_cast<char>((c - base + key) % 26 + base);
        } else {
            encrypted += c; // Leave non-alphabetic characters unchanged
        }
    }
    return encrypted;
}

int main() {
    std::string message = "Hello, world!";
    int key = 3; // Example key value

    // Encrypt the message using the key
    std::string encrypted = encrypt(message, key);
    std::cout << "Encrypted message: " << encrypted << std::endl;

    return 0;
}
