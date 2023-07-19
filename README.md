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
* quote handling

# Installation and Usage

Head to the code directory and build the project with `make` into an executable called **minishell**.
Then use BASH :-)

# Project structure

The project was splitted into the submodules `Lexer/Expander`, `Parser` and `Executor`.

## Lexer/Expander

The Lexer takes a stream of bytes, which the user types into the terminal via the `readline()` function.
Through the implemented lexical analysis the bztestream is split up into different tokens of type _WORD_, 
_I_RED(<)_, _O_RED(>)_, _I_RED_HD(<<)_ and _O_RED_APP(>>)_.
It also remove whitespaces at the end, merge WORDS (hell"o" -> hello) and expand TBD.

![alt text]([http://url/to/img.png](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.find-das-bild.de%2F&psig=AOvVaw06pMuFqEozz4ilWcHkQc8J&ust=1689863430219000&source=images&cd=vfe&opi=89978449&ved=0CA0QjRxqFwoTCJib4P79moADFQAAAAAdAAAAABAD)https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.find-das-bild.de%2F&psig=AOvVaw06pMuFqEozz4ilWcHkQc8J&ust=1689863430219000&source=images&cd=vfe&opi=89978449&ved=0CA0QjRxqFwoTCJib4P79moADFQAAAAAdAAAAABAD)









