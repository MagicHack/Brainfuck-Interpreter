# Brainfuck-Interpreter
Quick and dirty implementation of a Brainfuck interpreter in C++
(https://en.wikipedia.org/wiki/Brainfuck)

Hello, World! in Brainfuck:
> ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.

The default cell size is 8 bits (can be changed with the typedef).
The data array (tape) is 30000 cells long. Might make it dynamic in the future.

