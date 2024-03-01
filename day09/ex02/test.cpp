#include <iostream>
#include <string>

int main() {
    std::string str = "Hello123";
    std::string charsToFind = "0123456789";

    // Find the position of the first character not in the specified set
    size_t pos = str.find_first_not_of(charsToFind);

    if (pos != std::string::npos) {
        std::cout << "First character not in the set found at position: " << pos << std::endl;
        std::cout << "Character: " << str[pos] << std::endl;
    } else {
        std::cout << "All characters are in the specified set." << std::endl;
    }

    return 0;
}