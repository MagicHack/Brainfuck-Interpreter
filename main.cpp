#include <fstream>
#include <iostream>
#include <chrono>
#include "BrainfuckInterpreter.hpp"

int main(int argc, char* argv[]) {
    // Trying to read a program from a file or an argument
    std::string program = "";
    if(argc > 1){
        std::ifstream bfFile;
        bfFile.open(argv[1]);
        if(bfFile.fail()){
            program = argv[1];
        }else{
            std::string line;
            while(getline(bfFile, line)){
                program += line;
            }
        }
    }
    else{
        std::cout << "Paste your Brainfuck program here and press ctrl+d (or ctrl+z on Windows) :\n\n";
        std::string line;

        while(getline(std::cin, line)){
            program += line;
        }
    }
    // Using the interpreter
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