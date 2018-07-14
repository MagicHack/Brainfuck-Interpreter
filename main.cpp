#include <iostream>
#include <chrono>
#include "BrainfuckInterpreter.hpp"

int main() {
    static const int MAX_EMPTY_LINES = 2; // Max empty lines in a pasted code
    std::string program = "";

    std::cout << "Paste your Brainfuck program here (press enter " << MAX_EMPTY_LINES << " times):\n\n";

    std::string line;
    int emptyLinesCounter = 0;
    while(true){
        getline(std::cin, line);
        if(line.empty()){
            emptyLinesCounter++;
            if(emptyLinesCounter >= MAX_EMPTY_LINES) break;
        } else emptyLinesCounter = 0;

        program += line;
    }

    BrainfuckInterpreter interpreter(program);

    if(!interpreter.isValidProgram()){
        std::cout << "Invalid program\n";
        return 0;
    }
    std::cout << "Running the program..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    interpreter.run();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "\n\nElapsed time: " << elapsed.count() << " s\n";

    return 0;
}