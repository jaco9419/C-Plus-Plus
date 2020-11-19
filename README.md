# C-Plus-Plus
This is an educative repository to practice C++. It may include concepts and small projects.
Concepts are ordered from last to first. Most of this information is taken directly from Codecadem's C++ learning course.

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
