#include <iostream>
#include <string>
#include <map>
#include <algorithm>

// Function to perform frequency analysis on ciphertext
std::string frequencyAnalysis(const std::string& ciphertext) {
    // Map to store letter frequencies
    std::map<char, int> freqMap;

    // Count the frequency of each letter in the ciphertext
    for (char c : ciphertext) {
        if (std::isalpha(c)) {
            freqMap[c]++;
        }
    }

    // Sort the map by frequency in descending order
    std::vector<std::pair<char, int>> sortedFreq(freqMap.begin(), freqMap.end());
    std::sort(sortedFreq.begin(), sortedFreq.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    // Assuming 'e' is the most common letter in English, map it to 'e'
    std::map<char, char> mapping;
    char mostCommonLetter = 'e';
    for (auto& pair : sortedFreq) {
        mapping[pair.first] = mostCommonLetter--;
    }

    // Decrypt the ciphertext using the mapping
    std::string plaintext = ciphertext;
    for (char& c : plaintext) {
        if (std::isalpha(c)) {
            c = mapping[c];
        }
    }

    return plaintext;
}

int main() {
    std::string ciphertext = "Kroorz gr jrrg lw qrw wkh ehvw wkhuh lv";
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    std::string plaintext = frequencyAnalysis(ciphertext);
    std::cout << "Decrypted: " << plaintext << std::endl;

    return 0;
}
