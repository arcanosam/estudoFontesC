TODO
* fix:
  * [ ] Input of menu must be sanitized to prevent errors as choice an option that don't exists
* improvements:
  * [ ] add before menu re-print the system function calling 'clear' command
    * [ ] System messages printed by choiced options must be parameterized passing to makeMenu function or will be lost

_________________________________________________________________________

2015-06-23 - understanding stack architecture
* [x] Stack is not piling, the last element added must point to NULL and not the first one
  * After reading and meditate about Basic Architecture of a stack (in previous link), I understand that
there is no implementation error. I just not fully understand the implementation

_________________________________________________________________________

2015-06-21 - some refactoring
* modularization
  * add main file to root project
  * rename source origin to stack.c
* translate source to english and follow the stack's conventions here: https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29

_________________________________________________________________________

2015-06-18 - formating source
* Following:  http://www.gnu.org/prep/standards/standards.html#Formatting
  
_________________________________________________________________________

2015-06-17 - Found and fixed 11 warnings

* Char variables initialized with integer zero
* Printf specify formmatter %u changed to %p
* 'command' variabel not utilized - line commented
* Variável rs_scn criada para recepção dos retornos das funções: system e scanf
  * Impressão do resultado desta variável ao final da execução do programa por mera conveniência afim de evitar warning

_________________________________________________________________________


2015-06-16 - Fork my brother's github 
* Using xubuntu 15.04 x86_64 on virtualbox
* Make a project by import on Eclipse CDT Luna

_________________________________________________________________________
My brother originally written:

Developed in Debian. Running in command line with GCC and GDB 

1) Data Structure: Stack
* Source: stack.c
  * Features:
    * Insertion
  	* Search by value
  	* Exclusion
  	* Count stack size
  * Malloc and pointers are used. 

  * to compile:
    * gcc -g stack.c -o stack

  * to run:
    * to use gdb make sure to have installed: sudo apt-get install gdb
    * gdb ./stack  or just ./stack 

