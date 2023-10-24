#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

std::vector<std::string> get_words() {
    std::vector<std::string> v;
    std::ifstream myfile ("examples.txt");
    std::string line;
    while(getline (myfile,line))
        v.push_back(line);
    
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);
    return v;
}


void print_to_screen(std::vector<std::string> vec ) {
    for(int i=0; i<8; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
} 

//std::vector<
std::string take_input() {
    //std::vector<
    std::string input;
    std::cin >> input;
    return input;
}


int main() {
    std::vector<std::string> total = get_words();
    std::vector<std::string> ex_1;
    for(int i=0; i<8; i++)
        ex_1.push_back(total[i]);

    std::vector<std::string> ex_2;
    for(int i=8; i<16; i++)
        ex_2.push_back(total[i]);

    std::vector<std::string> ex_3;
    for(int i=16; i<24; i++)
        ex_3.push_back(total[i]);

    std::vector<std::string> ex_4;
    for(int i=24; i<32; i++)
        ex_4.push_back(total[i]);

    std::vector<std::string> ex_5;
    for(int i=32; i<40; i++)
        ex_5.push_back(total[i]);

    print_to_screen(ex_1);
    print_to_screen(ex_2);
    print_to_screen(ex_3);
    print_to_screen(ex_4);
    print_to_screen(ex_5);
    //print_to_screen(take_input());


    return 0;
}
