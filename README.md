# C-Plus-Plus
This is an educative repository to practice C++. It may include concepts and small projects.
Concepts are ordered from last to first. Most of this information is taken directly from Codecadem's C++ learning course.

<hr>

## 18) Memory Address
So we haved learned about references (aliases), which are created by using the & symbol in a variable declaration. But the & sign can have another meaning.

The “address of” operator, &, is used to get the memory address, the location in the memory, of an object.

Suppose we declare a variable called:

int porcupine_count = 3;<br>
Have you wondered where the variable porcupine_count is stored on the computer? We can find out by printing out &porcupine_count:

std::cout << &porcupine_count << "\n";<br>
It will return something like:

0x7ffd7caa5b54<br>
This is a memory address represented in hexadecimal. A memory address is usually denoted in hexadecimal instead of binary for readability and conciseness.

The double meaning of the & symbol can be tricky at first, so make sure to note:

When & is used in a declaration, it is a reference operator.<br>
When & is not used in a declaration, it is an address operator.

## 17) Pass-By-Reference
So what’s a good use case for references? Let’s take a look.

Previously, when we passed parameters to a function, we used normal variables and that’s known as pass-by-value. But because the variables passed into the function are out of scope, we can’t actually modify the value of the arguments.

Pass-by-reference refers to passing parameters to a function by using references. When called, the function can modify the value of the arguments by using the reference passed in.

This allows us to:

Modify the value of the function arguments.<br>
Avoid making copies of a variable/object for performance reasons.

The following code shows an example of pass-by-reference. The reference parameters are initialized with the actual arguments when the function is called:

<pre><code>void swap_num(int &i, int &j) {
 
  int temp = i;
  i = j;
  j = temp;
 
}
 
int main() {
 
  int a = 100;
  int b = 200;
 
  swap_num(a, b);
 
  std::cout << "A is " << a << "\n";
  std::cout << "B is " << b << "\n";
 
}</code></pre>

Notice that the int &i and int &j are the parameters of the function swap_num().

When swap_num() is called, the values of the variables a and b will be modified because they are passed by reference. The output will be:

A is 200<br>
B is 100<br>

Suppose we didn’t pass-by-reference here and have the parameters as simply int i and int j in the swap_num() function, then i and j would swap, but a and b wouldn’t be modified.

And the output will then be:

A is 100<br>
B is 200<br>

To reiterate, using references as parameters allows us to modify the arguments’ values. This can be very useful in a lot cases.

## 16) Destructors
So far, you’ve learned how to create and use objects. But there’s another part of the object lifecycle we need to cover: how to destroy them! Muahahaha.

It’s actually far less nefarious than it sounds; object destruction is really about tidying up and preventing memory leaks. A destructor is a special method that handles object destruction. Like a constructor, it has the same name as the class and no return type, but is preceded by a ~ operator and takes no parameters:

<pre><code>City::~City() {
 
  // any final cleanup
 
}</code></pre>

Inside you add any housekeeping that needs to happen before the object is destroyed. You generally won’t need to call a destructor; the destructor will be called automatically in any of the following scenarios:

The object moves out of scope.<br>
The object is explicitly deleted.<br>
When the program ends.

## 15) Constructors
Is there a way to give an object some data right when it gets created? We’re so glad you asked!

A constructor is a special kind of method that lets you decide how the objects of a class get created. It has the same name as the class and no return type. Constructors really shine when you want to instantiate an object with specific attributes.

If we want to make sure each City is created with a name and a population, we can use parameters and a member initializer list to initialize attributes to values passed in:

// city.hpp
<pre><code>class City {
 
  std::string name;
  int population;
 
public:
  City(std::string new_name, int new_pop);
 
};</code></pre>
 
// city.cpp
<pre><code>#include "city.hpp"

City::City(std::string new_name, int new_pop)
  // members get initialized to values passed in 
  : name(new_name), population(new_pop) {}
You could also write the definition like this:

City::City(std::string new_name, int new_pop) {
  name = new_name;
  population = new_pop;
}</code></pre>

However, a member initialization list allows you to directly initialize each member when it gets created.

To instantiate an object with attributes, you can do:

// inside main()
<code>City ankara("Ankara", 5445000);</code>

Now we have a City called ankara with the following attributes:

ankara.name set to "Ankara".
ankara.population set to 5445000.

## 14) Class Members
An empty class is pretty useless. Classes are designed to bring together related information and functionality — time to add stuff inside!

Components of a class are called class members. Just like you can get a string’s length using .length(), you can access class members using the dot operator (object.class_member).

There are two types of class members:

Attributes, also known as member data, consist of information about an instance of the class.<br>
Methods, also known as member functions, are functions that you can use with an instance of the class. We use a . before method names to distinguish them from regular functions.<br>
We encapsulate — or enclose for simpler user access — attributes and methods in a class like this:

<pre><code>class City {
 
  // attribute
  int population;
 
// we'll explain 'public' later
public:
  // method
  void add_resident() {
    population++;
  }
 
};</code></pre>

Unless we have a mostly empty class, it’s common to split function declarations from definitions. We declare methods inside the class (in a header), then define the methods outside the class (in a .cpp file of the same name).

How can we define methods outside a class? We can do this using ClassName:: before the method name to indicate its class like this:

<pre><code>int City::get_population() {
  return population;
}</code></pre>

Unlike with regular functions, we need to include the header file in the .cpp file where we define the methods.

Note: We must declare a method inside the class if we want to define it outside.

music.cpp

<pre><code>#include < iostream>
#include "song.hpp"

int main() {

  Song electric_relaxation;
  electric_relaxation.add_title("Electric Relaxation");

  std::cout << electric_relaxation.get_title() << std::endl;
  
}</code></pre>

song.hpp

<pre><code>#include < string>

// add the Song class here:
class Song {
  std::string title;

  public:
    void add_title(std::string new_title);
    std::string get_title();
};</code></pre>

song.cpp

<pre><code>#include "song.hpp"

// add Song method definitions here:
void Song::add_title(std::string new_title) {
  title = new_title;
};

std::string Song::get_title() {
  return title;
};</code></pre>

## 13) Function Templates
So how do we implement templates with actual code? Unlike regular functions, templates are entirely created in header files.

Templates let us choose the type implementation right when you call the function. The type we choose may apply to the return type, a parameter type, or both.

<pre><code>template < typename T >
T get_smallest(T num1, T num2) {
  
  return num2 < num1? num2 : num1;
  
}</code></pre>

## 12) Function Overload

In a process known as function overloading, you can give multiple C++ functions the same name. Just make sure at least one of these conditions is true:

Each has different type parameters.<br>
Each has a different number of parameters.

<pre><code>void print_cat_ears(char let) {
  std::cout << " " << let << "   " << let << " " << "\n";
  std::cout << let << let << let << " " << let << let << let << "\n";
}
 
void print_cat_ears(int num) {
  std::cout << " " << num << "   " << num << " " << "\n";
  std::cout << num << num << num << " " << num << num << num << "\n";
}</code></pre>

<pre><code>print_cat_ears('A');
print_cat_ears(4);</code></pre>

<pre><code> A   A 
AAA AAA
 
 4   4
444 444</code></pre>

## 11) Inline Functions

Once you set foot in the wild of C++ development, you may encounter the term “inline functions” with a couple different meanings. An inline function is a function definition, usually in a header file, qualified by inline like this:

<pre><code>inline 
void eat() {
 
  std::cout << "nom nom\n";
 
}</code></pre>

Using inline advises the compiler to insert the function’s body where the function call is, which sometimes helps with execution speed (and sometimes hinders execution speed). If you do use it, we recommend testing how it affects the execution speed of your program. The bottom line is inline is something you’ll probably encounter, but may never use.

However, you will sometimes also hear about “inline functions” that are just member functions (i.e. functions inside of classes — we’ll explain classes later) which have been defined and declared in a single line in a header file because the function body is so short:

<pre><code>// cookie_functions.hpp
 
// eat() belongs to the Cookie class:
void Cookie::eat() {std::cout << "nom nom\n";} </code></pre>

Please note that you should ALWAYS add the inline keyword if you are inlining functions in a header (unless you are dealing with member functions, which are automatically inlined for you).

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

<hr>

## Some Terms:

#### Pass-By-Reference
It refers to passing parameters to a function by using references. When called, the function can modify the value of the arguments by using the reference passed in.

#### Pass-By-Value
When we passed parameters to a function, we used normal variables and that’s known as pass-by-value. But because the variables passed into the function are out of scope, we can’t actually modify the value of the arguments.
