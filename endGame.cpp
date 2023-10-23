#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <sstream>

using namespace std;

void printResult(string test, string user, std::chrono::seconds::rep time){
        
    //-------Accuracy-------//
    cout << test << endl;
    cout << user << endl;

    istringstream iss1(test), iss2(user);
    string word1, word2;
    int correctWords = 0;
    int totalWords = 0;

    while (iss1 >> word1 && iss2 >> word2) {
        if (word1 == word2) {
            correctWords++;
        }
        totalWords++;
    }
    
    double accuracy = static_cast<double>(correctWords) / totalWords * 100;
    
    cout << "accuracy: " << accuracy << "%" << endl;
    //----------------------//
    
    //-------Net-WPM--------//
    double minutes = static_cast<double>(time) / 60.0;
    auto WPM = correctWords / minutes;
    cout << "WPM: " << WPM << endl;
    
    
    
    cout << time << endl;

}

int main(){
    
    string correctInput = "do this lead since out play too must still both";
    string userInput = "do thihafds led since our play too must still bot";

    auto start = std::chrono::high_resolution_clock::now();
    //sleep(30);
    //auto end = std::chrono::high_resolution_clock::now();
    auto end = start + std::chrono::seconds(24);
    
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    printResult(correctInput, userInput, duration);
    
//wpm
//accuracy

    

    return 0;
}
