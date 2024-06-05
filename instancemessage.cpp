#include <iostream>
#include <string>

// Function to encrypt a message using the Caesar cipher
std::string encrypt(const std::string& message, int shift) {
    std::string encrypted = "";
    for (char c : message) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            encrypted += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            encrypted += c; // Leave non-alphabetic characters unchanged
        }
    }
    return encrypted;
}

// Function to decrypt a message using the Caesar cipher
std::string decrypt(const std::string& encrypted, int shift) {
    return encrypt(encrypted, -shift); // Decrypting is just shifting in the opposite direction
}

int main() {
    std::string message = "Hello, world!";
    int shift = 3; // Example shift value

    // Encrypt the message
    std::string encrypted = encrypt(message, shift);
    std::cout << "Encrypted message: " << encrypted << std::endl;

    // Decrypt the message
    std::string decrypted = decrypt(encrypted, shift);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
