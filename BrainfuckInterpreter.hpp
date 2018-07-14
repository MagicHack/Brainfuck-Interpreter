#ifndef BRAINFUCK_BRAINFUCKINTERPRETER_HPP
#define BRAINFUCK_BRAINFUCKINTERPRETER_HPP

#include <iostream>
#include <vector>


class BrainfuckInterpreter {
public:
    BrainfuckInterpreter(std::string program = "");
    bool isValidProgram();
    bool isValidProgram(std::string program);
    void run();
    bool step();
    void reset();

private:
    size_t dataPointer_;
    size_t instructionPointer_;
    std::vector<char> data_;
    std::string program_;
};


#endif //BRAINFUCK_BRAINFUCKINTERPRETER_HPP
