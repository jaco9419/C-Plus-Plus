# C-Plus-Plus
This is an educative repository to practice C++. It may include concepts and small projects.
Concepts are ordered from last to first. Most of this information is taken directly from Codecadem's C++ learning course.

## 10) Getting a Header Yourself

If your program keeps growing, you may have to scroll through many declarations before you see main(). That doesn’t seem like the best way to do things. Plus you don’t want to keep declaring the same functions over and over for different files — making changes would be incredibly tiresome!

Well, you can take those function declarations and move them all over to a header file, another file — usually with the same name as the file with all of the function definitions — with the extension .hpp or .h. For example, if your function definitions are in my_functions.cpp, the corresponding header file would be my_functions.hpp or my_functions.h.

So how do you bring everything from a header file into scope for another file? Do you just link the header in the compilation statement like you did with the second .cpp file?

As it turns out, with headers, you can just add #include "my_functions.hpp" to the very top of main.cpp:

<code>#include "my_functions.hpp"</code>

Boom! This line pastes in everything from my_functions.hpp. Now you have access to all of the function declarations you stowed away in your header.

## 9) Multi-File Programs

main.cpp

<pre><code>#include < iostream >
#include < cmath >

// Add declarations here:
double average(double num1, double num2);
int tenth_power(int num);
bool is_palindrome(std::string text);

int main() {
  
  std::cout << is_palindrome("racecar") << "\n";
  std::cout << tenth_power(3) << "\n";
  std::cout << average(8.0, 19.0) << "\n";
  
}</code></pre>

my_functions.cpp

<pre><code>#include < iostream >
#include < cmath >

// Add definitions here:
double average(double num1, double num2) {
  return (num1 + num2) / 2;
}

int tenth_power(int num) {
  return pow(num, 10);
}

bool is_palindrome(std::string text) {
  std::string reversed_text = "";
  
  for (int i = text.size() - 1; i >= 0; i--) {
    reversed_text += text[i];
  }
  
  if (reversed_text == text) {
    return true;
  }
  
  return false;
}</code></pre>

Terminal:

<code>$ g++ main.cpp my_functions.cpp</code>


## 8) Random Numbers

<pre>
<code>#include < iostream >
#include < stdlib.h > // Not sure if this
#include < time.h > // and this are necessary (No spaces)

int main() {
  
  // This seeds the random number generator:
  srand (time(NULL));
  // Use rand() below to initialize the_amazing_random_number
  int the_amazing_random_number = rand() % 80;
  std::cout << the_amazing_random_number;
}</code>
</pre>

## 7) Adding and Removing Elements
Often, we start with a vector that’s either empty or a certain length. As we read or compute data we want, we can grow the vector as needed.

<code>.push_back()</code>
To add a new element to the “back”, or end of the vector, we can use the .push_back() function.

For example, suppose we have a vector called dna with three letter codes of nucleotides:

<code>std::vector<std::string> dna = {"ATG", "ACG"};</code>
  
It would look like:

ATG, ACG

We can add elements using .push_back():

<code>dna.push_back("GTG");</code><br>
<code>dna.push_back("CTG");</code>

So now dna would look like:

ATG, ACG, GTG, CTG

<code>.pop_back()</code>

You can also remove elements from the “back” of the vector using .pop_back().

<code>dna.pop_back();</code>

Notice how nothing goes inside the parentheses.

The vector would now look like:

ATG, ACG, GTG

because CTG is removed!

Note: If you have programmed in other languages, be aware that .pop_back() has no return value in C++.

## 6) Vectors

Vectors are a sequence of elements that you can access by an index.

<code>std::vector<int> even = {2, 4, 6, 8, 10};</code>
  
The first index in a vector is 0.

Some of the functions that come with vectors:

<code>.push_back()</code><br>
<code>.pop_back()</code><br>
<code>.size()</code><br>

We can use a for loop to iterate through a vector.

## 5) Debugging

In C++, there are many different ways of classifying errors, but they can be boil down to four categories:

<strong>-Compile-time errors:</strong> Errors found by the compiler.

<strong>-Link-time errors:</strong> Errors found by the linker when it is trying to combine object files into an executable program.

<strong>-Run-time errors:</strong> Errors found by checks in a running program.

<strong>-Logic errors:</strong> Errors found by the programmer looking for the causes of erroneous results.

### 5.1- Compile-time Errors

When we are writing C++ programs, the compiler is our first line of defense against errors.

There are two types of compile-time errors:

<strong>Syntax errors:</strong> Errors that occur when we violate the rules of C++ syntax.

<strong>Type errors:</strong> Errors that occur when there are mismatch between the types we declared.

Some common syntax errors are:

Missing semicolon ; <br>
Missing closing parenthesis ), square bracket ], or curly brace }

Some common type errors are:

Forgetting to declare a variable<br>
Storing a value into the wrong type

### 5.2- Link-time Errors

Sometimes the code compiles fine, but there is still a message because the program needs some function or library that it can’t find. This is known as a link-time error.

As our program gets bigger, it is good practice to divide the program into separate files. After compiling them, the linker takes those separate object files and combines them into a single executable file. Link-time errors are found by the linker when it is trying to combine object files into an executable file.

Some common link-time errors:

Using a function that was never defined (more on this later)<br>
Writing Main() instead of main()

### 5.3- Run-time Errors

If our program has no compile-time errors and no link-time errors, it’ll run. This is where the fun really starts.

Errors which happen during program execution (run-time) after successful compilation are called run-time errors. Run-time errors occur when a program with no compile-time errors and link-time errors asks the computer to do something that the computer is unable to reliably do.

It happens after we give the ./ execute command:

<code>./a.out</code>

Some common run-time errors:

Division by zero also known as division error. These types of error are hard to find as the compiler doesn’t point to the line at which the error occurs.<br>
Trying to open a file that doesn’t exist<br>
There is no way for the compiler to know about these kinds of errors when the program is compiled.

### 5.4- Logic Errors

Once we have removed the compile-time errors, link-time errors, and run-time errors, the program runs successfully. But sometimes, the program doesn’t do what we want it to do or no output is produced. Hmmm…

These types of errors which provide incorrect output, but appears to be error-free, are called logical errors. These are one of the most common errors that happen to beginners and also usually the most difficult to find and eliminate.

Logical errors solely depend on the logical thinking of the programmer. Your job now is to figure out why the program didn’t do what you wanted it to do.

Some common logic errors:

Program logic is flawed<br>
Some “silly” mistake in an if statement or a for/while loop<br>

Note: Logic errors don’t have error messages. Sometimes, programmers use a process called test-driven development (TDD), a way to give logic errors error messages and save yourself a lot of headaches!

## 4) User Input

Another way to assign a value to a variable is through user input. A lot of times, we want the user of the program to enter information for the program.

We have cout for output, and there is something called cin that’s used for input!

<code>std::cout << "Enter your password: ";</code>
<code>std::cin >> password;</code>

The name cin refers to the standard input stream (pronounced “see-in”, for character input). The second operand of the >> operator (“get from”) specifies where that input goes.
<pre>
<code>#include <iostream>

int main() {
  
  int tip = 0;
  
  std::cout << "Enter tip amount: ";
  std::cin >> tip;
  std::cout << "You paid " << tip << " dollars.\n";
  
}</code>
</pre>

## 3) Variables and data types

In C++ you declare a variable by typing its data type before it. They can be:

-<code>int</code>: integer numbers

-<code>double</code>: floating-point numbers

-<code>char</code>: individual characters

-<code>string</code>: a sequence of characters

-<code>bool</code>: true/false values

<code>int score;</code>

The int is the type of the variable.
The score is the name of the variable.
The ; is how we end a statement.

In C++, variable names consist only of upper/lower case letters, digits, and/or underscores. C++ is known as a strongly typed language.

## 2) Compile and Execute

<strong>Compile:</strong> A computer can only understand machine code. A compiler can translate the C++ programs that we write into machine code. To compile a file, you need to type g++ followed by the file name in the terminal:

<code>g++ hello.cpp</code>
The compiler will then translate the C++ program hello.cpp and create a machine code file called a.out.

<strong>Execute:</strong> To execute the new machine code file, all you need to do is type ./ and the machine code file name in the terminal:

<code>./a.out</code>
The executable file will then be loaded to computer memory and the computer’s CPU (Central Processing Unit) executes the program one instruction at a time.

### Naming Executable

<code>g++ hello.cpp -o hello</code>

## 1) Output

High five! We just got your first program to run.

C++, like most programming languages, runs line by line, from top to bottom. Here is the structure of a C++ program:

Program Structure

In between the curly braces is what we are going to focus on for now.

<code>std::cout << "Hello World!\n";</code>

-<code>std::cout</code> is the “character output stream”. It is pronounced “see-out”.

-<code><<</code> is an operator that comes right after it.

-<code>"Hello World!\n"</code> is what’s being outputted here. You need double quotes around text. The \n is a special character that indicates a new line.

-<code>;</code> is a punctuation that tells the computer that you are at the end of a statement. It is similar to a period in a sentence.
