#ifndef BRAINFUCK_BRAINFUCKINTERPRETER_HPP
#define BRAINFUCK_BRAINFUCKINTERPRETER_HPP

#include <iostream>
#include <vector>
typedef int8_t cellType; // Cell type can be made larger if needed (16, 32, 64)

class BrainfuckInterpreter {
public:
    BrainfuckInterpreter(std::string program = "");
    // Validity check (checks for mismatched brackets)
    bool isValidProgram();
    bool isValidProgram(std::string program);
    // Run the complete program
    void run();
    // Run 1 instruction
    bool step();
    // Reset all pointers and data to 0
    void reset();
private:
    size_t dataPointer_;
    size_t instructionPointer_;
    std::vector<cellType> data_;
    std::string program_;
};

#endif //BRAINFUCK_BRAINFUCKINTERPRETER_HPP
