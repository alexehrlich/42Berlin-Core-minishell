# 42Berlin-Core-minishell

This group project of the 42 core curriculium is about writing our own shell program by recreating (at least some of) the functionality of BASH.
Due to its lack of usage it is baptized ushelless. The learnings of the project on the other hand are anything else
but useless.
We learned to organize a big problem in different submodules, determine interfaces between them and organize our workflow with a shared repository.

# Fuctionality

* connect multiples commands via pipes |
* use redirections and heredocs < > << >>
* builtin functions:
   * echo with option -n
   * cd
   * export
   * unset
   * env
   * exit
* working command history
* handling signals: control+D, control+C, control+\
* environmental variables
* inspecting the last exit code with $?
* quote handline

Read minishell.pdf (LINK) for detailed project instruction. 

# Installation and Usage

Head to the code directory and build the project with `make` into an executable called **minishell**.
Then use BASH :-)

# Project structure

The project was splitted into the submodules `Lexer/Expander`, `Parser` and `Executor`.

## Lexer/Expander

The Lexer takes a stream of bytes, which the user types into the terminal via the `readline()` function.
Through the implemented lexical analysis the bztestream is split up into different tokens of type _WORD_, 
_I_RED(<)_, _O_RED(>)_, _I_RED_HD(<<)_ and _O_RED_APP(>>)_.
It also remove whitespaces at the end, merge WORDS (hell"o" -> hello) and expand variables (e.g. $PATH).

IMAGE of lexer workflow.

## Parser

The parser takes the linked list of tokens and converts it into a linked list of commands. Information about arguments, pipes, redirections and command type (BUILTIN or PATH) is extracted by the parsing algorithm and stored inside a command struct.
Find the flow chart of the parsing algorithm here. (Link to the pdf)

IMAGE of parser workflow.

## Executor

The executor takes the linked list of commands and executes them in the desired way. If there is only a single BUILTIN command (e.g. cd) called, the command gets executed in the current minishell-process. If a PATH command or piped mixec commands are called (e.g. echo  hello | grep hello) the minishell-process forks child processes to execute every command in its own child process and waits for its execution and grabs the exit code to give it back to the calling process.

IMAGE of Executor workflow.











