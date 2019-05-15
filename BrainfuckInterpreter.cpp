#include "BrainfuckInterpreter.hpp"

static const size_t MIN_DATA_ARRAY_LENGHT = 30000;

// The 8 Brainfuck instructions
static const char INCREMENT_POINTER = '>';
static const char DECREMENT_POINTER = '<';
static const char INCREMENT_DATA    = '+';
static const char DECREMENT_DATA    = '-';
static const char OUTPUT            = '.';
static const char INPUT             = ',';
static const char BEGIN_LOOP        = '[';
static const char END_LOOP          = ']';

BrainfuckInterpreter::BrainfuckInterpreter(std::string program) : program_(program) {
    dataPointer_ = instructionPointer_ = 0;
    data_ = std::vector<cellType>(MIN_DATA_ARRAY_LENGHT, 0); // Initialize the data array at 0
};

void BrainfuckInterpreter::run() {
    while(step());
}

bool BrainfuckInterpreter::step() {
    switch (program_[instructionPointer_]){
        case INCREMENT_POINTER:
            dataPointer_++;
            break;
        case DECREMENT_POINTER:
            dataPointer_--;
            break;
        case INCREMENT_DATA:
            data_[dataPointer_]++;
            break;
        case DECREMENT_DATA:
            data_[dataPointer_]--;
            break;
        case OUTPUT:
            std::cout << char(data_[dataPointer_]);
            break;
        case INPUT:
            std::cin >> data_[dataPointer_];
            break;
        case BEGIN_LOOP:
            if(!data_[dataPointer_]){
                int loopCounter = 1;
                do{
                    instructionPointer_++;
                    if(program_[instructionPointer_] == BEGIN_LOOP) loopCounter++;
                    else if(program_[instructionPointer_] == END_LOOP) loopCounter--;
                } while(loopCounter);
            }
            break;
        case END_LOOP:
            if(data_[dataPointer_]){
                int loopCounter = 1;
                do{
                    instructionPointer_--;
                    if(program_[instructionPointer_] == BEGIN_LOOP) loopCounter--;
                    else if(program_[instructionPointer_] == END_LOOP) loopCounter++;
                } while(loopCounter);
            }
            break;
        default: // Do nothing, all unknown instructions are treated as a comment
            break;
    }
    instructionPointer_++;
    return instructionPointer_ < program_.size();
}

bool BrainfuckInterpreter::isValidProgram() {
    return isValidProgram(program_);
}

bool BrainfuckInterpreter::isValidProgram(std::string program) {
    int loopCounter = 0;
    for(auto instruction: program){
        if(instruction == BEGIN_LOOP) loopCounter++;
        else if(instruction == END_LOOP) loopCounter--;
    }
    // loopCounter should be 0, else there is a mismatched loop bracket
    return !loopCounter;
}

void BrainfuckInterpreter::reset() {
    std::fill(data_.begin(), data_.end(), 0);
    dataPointer_ = instructionPointer_ = 0;
}
