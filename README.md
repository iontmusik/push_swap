This project consists of coding a program that finds the lowest possible number of moves to
sort a random list of integers using 2 stacks and a limited set of operations  
For more detailed information, look at the subject of this project.

🛠️ Usage
Requirements
The function is written in C language and thus needs the gcc compiler and some standard C libraries to run.

Instructions
1. Compiling the program

To compile, go to the program path and run:

$ make
2. Executing the program

To execute the program, run:

$ ./push_swap $ARG
where $ARG is a space separated list of integers, e.g. ARG="1 5 2 4 3"

Actions
PUSH

Take the first element at the top of one stack and put it at the top of the other; do nothing if the origin stack is empty.

pa - top element of stack b goes to top of stack a.
pb - top element of stack a goes to top of stack b.
SWAP

Swap the first 2 elements at the top of the stack; do nothing if there is only one or no elements.

sa - swap stack a.
sb - swap stack b.
ss - sa and sb at the same time.
ROTATE

Shift up all elements of the stack by one; the first element becomes the last.

ra - rotate stack a.
rb - rotate stack b.
rr - ra and rb at the same time.
REVERSE ROTATE

Shift down all elements of the stack by one; the last element becomes the first.

rra - reverse rotate stack a.
rrb - reverse rotate stack b.
rrr - rra and rrb at the same time.
USED ALGORITHM

📋 Testing
You can use this third party testers to fully test the project:

SimonCROS/push_swap_complexity_tester
laisarena/complete_push_swap_tester
And a useful to visualize the movements:

o-reo/push_swap_visualizaer
