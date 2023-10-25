#include <thread>
#include <chrono>
#include <vector>
#include <curses.h>
#include <fstream>
#include <random>
#include <algorithm>

std::vector<std::string> words;
std::string init_msg;

void getWords(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        exit(1);
    }
    
    std::string line;
    while(std::getline(file, line)) {
        words.push_back(line);
    }
    file.close();
}

void genRand() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(words.begin(), words.end(), g);

    for(size_t i = 0; i < 15 && i < words.size(); ++i) {
        if(i != 0) init_msg += " ";
        init_msg += words[i];
    }
}


int inputLoop = 1;
int temp = 0;
int start = 1;
char ch;
int row,col;
int wrong,correct;
int total;
float percent;
bool gameOver = false;

void readInput() {
  int i = 0;
  auto start_time = std::chrono::steady_clock::now();
  mvaddch(row/2, (col-init_msg.length())/2 + i-1, '>');
  while (inputLoop) {
    ch = getch();
        if(!gameOver){
            if (ch == init_msg[i]) {
                mvaddch(row/2, (col-init_msg.length())/2 + i-1, ' ');
                
                init_msg[i] = ' ';
                mvprintw(row/2,(col-init_msg.length())/2,"%s",init_msg.c_str());
                i++;
                mvaddch(row/2, (col-init_msg.length())/2 + i-1, '>');
                correct++;
            } else {
                wrong++;
            }
        }
    if (init_msg[i] == '\0' && !gameOver) {
        gameOver = true;
        mvaddch(row/2, (col-init_msg.length())/2 + i-1, ' ');
        auto end_time = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
        total = wrong + correct;
        percent = ((float)(correct-wrong)/correct)*100 ;
      getmaxyx(stdscr,row,col);
      mvprintw(row/2,(col-37)/2,"Your total number of key presses: %d", total);
      mvprintw((row+2)/2,(col-44)/2,"Your total number of correct key presses: %d", correct);
      mvprintw((row+4)/2,(col-42)/2,"Your total number of wrong key presses: %d", wrong);
      mvprintw((row+6)/2,(col-20)/2, "Time Taken: %ld seconds", duration);
      mvprintw((row+8)/2,(col-21)/2, "Accuracy: %.2f percent", percent);
      mvprintw((row+10)/2,(col-18)/2,"Press ESCAPE to quit.");
    }
    if (ch == 27) {
      inputLoop = 0;
    }
  }
}

int main() {
  getWords("examples.txt");
  genRand();

    initscr();
  noecho();
  getmaxyx(stdscr,row,col);
  mvprintw(row/2,(col-init_msg.length())/2,"%s",init_msg.c_str());
  curs_set(0);
  std::thread input(readInput);
  input.join();
  endwin();


  return 0;
}
