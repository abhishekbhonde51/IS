

// C++ Example: Dictionary Attack
// This program will read a list of passwords from a file and attempt to guess the target password.

// 1. Create a File with Potential Passwords
// First, create a file named passwords.txt with the following content:

// Copy code
// 123456
// password
// 123456789
// 12345678
// 12345
// 1234567
// abc
// qwerty


#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string target = "abc";  // The password to guess
    std::ifstream infile("passwords.txt");
    std::string password;

    if (!infile) {
        std::cerr << "Unable to open file passwords.txt";
        return 1;
    }

    bool found = false;
    while (std::getline(infile, password)) {
        if (password == target) {
            std::cout << "Password found: " << password << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Password not found in the dictionary." << std::endl;
    }

    infile.close();
    return 0;
}
