# Operating Systems Exercise 1, Semester B 2023-2024
## Version 1.1 - April 14, 2024
### Topics
- Unix tools
- Debugging
- Libraries
- Process creation
- Pipes
- File descriptors
### Purpose
Align your skills with using Unix tools, building libraries, debugging, and working with processes using fork, exec, pipe, and file descriptor copying.

### General Instructions
- You can submit the exercise on Linux (using a virtual machine), macOS (install Xcode and Xcode command line tools), or Windows (using WSL).
- If not using Linux, you must use POSIX APIs only. Do not use COCOA (Apple) or Windows APIs.
- Ensure your code runs on Linux to avoid disputes during evaluation.
- You may write the exercise in C or C++.
- Each exercise must be submitted in a separate directory containing the code, screenshots, or additional files.
- Submit a recursive Makefile for each exercise that builds all parts of the exercise using make all and cleans them with make clean.
- Submit one tar.gz file containing all parts of the exercise. You can learn about tar(1) and gzip(1) online and in their respective man pages. See instructions on creating tar.gz at the end.
- All sub-tasks must be submitted.
- The exercises must be submitted in pairs. Students affected by the current situation (e.g., reservists, partners of reservists, evacuees, etc.) can declare their status and submit in groups of three.
- All group members are responsible for the entire exercise and must defend all parts of the submission.
### Exercise 1 - Compilation and Debugging on Linux - 10 Points
Write three programs that crash in the following ways:

1. Stack overflow (e.g., due to infinite recursion).
2. Division by zero.
3. Undefined memory usage (e.g., reading or writing to an undefined address, such as 0xdeadbeef).


Generate a core dump, open it using a debugger, and demonstrate opening the core with and without debug info (using the -g flag during compilation). Show the core opening with a text-based debugger (using commands such as where or print) and with a graphical debugger (e.g., ddd). If you do not have a graphical debugger installed, install it (e.g., using sudo apt install ddd on Ubuntu).

Submit the code and screenshots of each step.

### Exercise 2 - Using a Library (Mathematical Library) - 10 Points
Write a program Poisson that calculates Poisson distribution probability.

The program should accept 2 arguments (via argc and argv), representing λ (first argument) and k (second argument).

If the program receives more or less than 2 arguments, it should print "Error\n" and exit.

If the program receives exactly 2 arguments, it should print the value of P(X=k) with precision of long double (using the expf(3) function).

Note: To use functions from the mathematical library, compile with the -lm flag and include the math library header (math.h for C, cmath for C++).

Submit the Makefile, code, and a screenshot of a sample run.

### Exercise 3 - Building a Library - 10 Points
Based on Exercise 2, build a function poisson that calculates the Poisson distribution.

Compile it into a dynamic library (shared object) named libpoisson.so.

Write a program that uses the library and calculates Poisson distribution for 5 values:

- λ = 1, k = 1
- λ = 2, k = 10
- λ = 2, k = 2
- λ = 3, k = 3
- λ = 3, k = 100
Print each value on a separate line.

Submit the Makefile, code, and a screenshot of a sample run.

### Exercise 4 - Code Coverage - 20 Points
Using the implementation of Dijkstra's algorithm from GeeksforGeeks, modify the program to support accepting a new graph inside a for (;;) loop (reading the graph from stdin using scanf or cin). Ensure the program handles input validation (not too many or too few edges per row, no negative edge weights).

Test the program and your tests using gcov.

Show that your tests cover all code submitted, including edge cases (e.g., invalid input, too many edges, too few rows, negative edge weights).

Submit the code, Makefile, gcov output, and screenshots of the run.

### Exercise 5 - Profiling - 20 Points
Implement three solutions to the Max Subarray Sum problem with complexities O(n), O(n^2), and O(n^3).

The programs should accept two arguments:

1. Random seed (for use with srand).
2. Input size (number of generated numbers).
Generate random input (using rand(3)) and run the algorithm within a function. The random numbers should be uniformly distributed within the range (-25, 74). Include negative numbers to ensure the subarray sum is not trivially the entire array.

Run the three solutions on inputs of size 100, 1000, 10000.

Demonstrate the runtime of the algorithm versus the time to generate random numbers using gprof.

Submit the code for the three programs, Makefile, screenshots, and gprof output.

### Exercise 6 - Using Pipes and Process Creation - 30 Points
Implement a phone book using a text file where each line contains a name and phone number separated by a comma, ending with a newline (e.g., Nezer Zaidenberg,054-5531415\n). The file can contain dozens or hundreds of records.

Implement two programs:

1. add2PB - Adds a new record to the phone book. The program should accept a name (which may contain spaces) and a phone number, separated by a comma. Ensure that the name does not contain commas and that the record ends with a line feed.
2. findPhone - Finds the phone number of a person provided as argv[1] by using the commands cat, grep, awk, sed, and cut. Create processes using fork(2) and execXX(2) and copy file descriptors using dup(2) or dup2(2).
Submit the Makefile, code for both programs, and a sample run (e.g., screenshot).

Example solution for finding a phone number:

- Use grep to filter the line containing the name.
- Use sed to replace spaces with a specific character and replace the comma with a space to create a second column.
- Use awk to print the second column (the phone number).
#### Working with tar and gzip
Old School - Two Commands
1. Use tar to bundle files:

- tar -cvf mytarfile.tar mydirectory
- To extract: tar -xvf mytarfile.tar
2. Use gzip to compress:

- gzip myfile
- To decompress: gunzip myfile.gz
#### Modern Single Command
Modern versions of tar support compression:

- To compress: tar -zcvf mycompressedfile.tgz mydirectory
- To extract: tar -zxvf mycompressedfile.tgz
For more details, see the tar manual.

#### Important
- This exercise counts for 10% of the final course grade.
- Defense of the exercise counts for an additional 5%. Treat the exercise accordingly!
- Write everything in English and include a README file.







