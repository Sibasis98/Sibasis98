#include <iostream>
#include <string>

std::string rotateString(const std::string& input, int swap_ch) {
    int n = input.length();
    
    if (n < swap_ch) return input;  // No need to rotate if the string has less than 3 characters

    for
    std::string rotated = input.substr(2, n) + input.substr(0, 2);
    return rotated;
}

int main() {
    std::string input = "abcdhi";
    std::string output = rotateString(input);
    
    std::cout << "Output: " << output << std::endl;
    return 0;
}
