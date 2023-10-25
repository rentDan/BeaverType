#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> splitVector(const std::vector<std::string>& words, size_t n) {
    std::vector<std::vector<std::string>> subVectors;

    for (size_t i = 0; i < words.size(); i += n) {
        std::vector<std::string> sub(words.begin() + i, words.begin() + std::min(i + n, words.size()));
        subVectors.push_back(sub);
    }

    return subVectors;
}

std::string concatenateSubvectors(const std::vector<std::vector<std::string>>& subVectors) {
    std::string result;
    
    for (const auto& sub : subVectors) {
        for (const auto& word : sub) {
            result += word + " ";  // Add a space between words
        }
    }

    // Optional: Remove the trailing space if you added spaces between words
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}


int main() {
    std::vector<std::string> words = {"word1", "word2", "word3", "word4", "word5", "word6", "word7", "word8", "word9"};

    auto subVectors = splitVector(words, 4);

    // Print subVectors
    for (const auto& sub : subVectors) {
        for (const auto& word : sub) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    std::string concatenated = concatenateSubvectors(subVectors);
    std::cout << concatenated << std::endl;

    return 0;
}
