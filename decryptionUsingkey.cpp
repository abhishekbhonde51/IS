#include <iostream>
#include <string>

// Function to decrypt a message encrypted with the Caesar cipher using a given key
std::string decrypt(const std::string& encrypted, int key) {
    std::string decrypted = "";
    for (char c : encrypted) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            // To decrypt, we need to shift in the opposite direction (subtract the key)
            int shift = (c - base - key + 26) % 26;
            decrypted += static_cast<char>(shift + base);
        } else {
            decrypted += c; // Leave non-alphabetic characters unchanged
        }
    }
    return decrypted;
}

int main() {
    std::string encrypted_message = "Khoor, zruog!";
    int key = 3; // Example key value

    // Decrypt the message using the key
    std::string decrypted = decrypt(encrypted_message, key);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
