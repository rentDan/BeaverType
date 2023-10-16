#include <iostream>
#include <string>
#include <vector>

void print_to_screen() {
    std::cout << "Try typing this." << std::endl;
} 

std::string take_input() {
    std::string input;
    std::cin >> input;
    return input;
}


int main() {
    print_to_screen();
    std::cout << take_input() << std::endl;

    return 0;
}
