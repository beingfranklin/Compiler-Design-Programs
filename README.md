Compiler Design Lab
===================

### Day 1
1. Design and implement a lexical analyzer for given language using C and the lexical analyzer should ignore redundant spaces, tabs and new lines.

![Lexical Analyser](https://raw.githubusercontent.com/beingfranklin/Compiler-Design-Lab/master/LexicalAnalyser.png)


### Day 2
2. Write program to design of lexical analyzer using LEX

i) Write a program to check whether the given string is valid according to the regular definition   `0(10|01)*`.

ii) Write a program to list the identifiers from a given C program.

**Steps To Compile**
* Save file as `lexical-lextool.l`.
* Run `lex lexical-lextool.l`.
* Then a file `lex.yy.c` will be generated.
* Compile it using gcc by typing `gcc lex.yy.c -lfl`
* Execute the `./a.out` file.


### Day 3

3. Write program to design parser for arithmetic expressions using YACC

i) Write a program to check the syntax of switch statement in C.

ii) Program to recognize a valid arithmetic expression that uses operator `+, – , * and /`.

~~iii) Program to recognize a valid variable which starts with a letter followed by any   number of letters or digits.~~

iv) Write a program to implement arithmetic calculator.


**Steps To Compile**

* Save lex file as `YourFileName.l` and YACC file as `YourFileName.y`.
* Run `lex YourFileName.l`. *(Here this command creates a `c` file `lex.yy.c`)*
* Compile YACC by using `yacc -d YourFileName.y` and `y.tab.c` file is generated. *(Here the tokens are generated and stored into `y.tab.c` )*
* Now Compile it together using gcc by typing `gcc y.tab.c lex.yy.c`.
* Execute the `./a.out` file.

### Day 4

4. Write program to design recursive descent parser

**Steps To Compile**
* Save file as `pgm_name.c` .
* Compile it using gcc by typing `gcc pgm_name.c
* Execute the `./a.out` file.

### To Complete

5. Write a program to simulate `FIRST` and `FOLLOW` of any given grammar.

6. Write program to implement LL (1) parser

7. Write program to implementation of Operator precedence parsing 

8. Write a program to perform constant propagation.

9. Write program to generate Intermediate Code for arithmetic expressions

10. Write program to design a code generator for arithmetic expressions.

11. Write program to find ε – closure of all states of any given NFA with ε transition.
