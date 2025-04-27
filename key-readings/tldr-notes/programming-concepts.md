# Programming Concepts
Miscellaneous programming concepts. 

Includes essential general background info and some language specific background info and best practices (mainly C).

## Index
- [Programming](#programming)
- [Programming Paradigms](#programming-paradigms)
- [Software -> Machine Code](#software---machine-code)
- [Common Tips](#common-tips)
- [SOLID Principles](#solid-principles)
- [NASA: The Power of 10](#nasa-the-power-of-10)
- [C](#c)
- [Python](#python)
- [C++](#c++)

## Programming
-	“We will never be rid of code, because code represents the details of the requirements. At some level those details cannot be ignored or abstracted; they have to be specified. And specifying requirements in such detail that a machine can execute them is programming. Such a specification is code” – Robert C. Martin in *Clean Code: A Handbook of Agile Software Craftsmanship*

-	“We need to keep in mind that all living languages, both natural and synthetic, must evolve or perish” – Cris Kobryn in *UML Distilled*

## Programming paradigms
- Procedural
  - Language made for users to organize and execute tasks in a sequence of procedures/routines to run tasks step-by-step
  - C, Pascal, Fortran
- Functional

  - Language made for users to write in an immutable way to represent software as the evaluation of mathematical functions
  - Avoids side effects; uses higher order functions, lambda expressions, and recursion
  - Haskell, Lisp, Scala, OCaml
- Object-oriented
  - Language made for users to encapsulate, organize, and abstract behavior using classes
  - Java, C++, Python

  - Method vs Function
    - A “function” is an abstraction for a block of code that performs a single task- written independent of classes
    - A “method” is a function written for a particular class

  - Attribute/field vs element
    - A variable in a C struct is called an “element”
    - A variable in a Java class is called a “field” or “attribute” (“field” more commonly used)

  - Overriding vs overloading
    - Overloading 
      - Overloading is when a function is defined multiple times but with different signatures (different parameter types or different number of parameters)
      - Python doesn’t directly support overloading like Java, but default parameters establish the same idea
      - C++ does support overloading just like Java
      - C doesn’t support overloading

    - Overriding
      - Overriding is when a subclass of a class redefines a method w/ same signature
      - Python, Java, C++ support overriding

  - Super class vs parent class
    - Synonymous, where “super class” has some more technical nuances…

  - 5 pillars of OOP
    - Encapsulation
      - Bundling data/methods into classes to enforce modularity/security/portability 

    - Abstraction
      - Hiding complex implementation details and exposing just essential features via interfaces / abstract classes

    - Inheritance
      - Allowing a class to inherit its properties and methods from another class allowing code reuse and hierarchical relationships

    - Polymorphism
      - Allowing an interface to take various forms via overriding/interfaces

    - Composition
      -  Defining objects w/ other objects as their attributes to enforce modularity and organization 

  - Namespaces
    - Container to organize code and prevent name conflicts by grouping related identifiers (variables, functions, classes)
    - Supported in C++, C#, Java, Python, etc
    - Allows grouping around related items for better readability and navigation
    - Extensibility
      - Can safely modify and add features without conflicting w/ existing items
    - “global namespace”
      - The default scope in C++ that encompasses all software

### Rust & Zig
  - Both Rust and Zig are modern languages that build on procedural concepts at its core, but with added memory management features for protection and OOP aspects
  - Both code in Rust and Zig compile down to C first before compiling down to machine code

  - Rust
    - Implements memory safety/concurrency through ownership model and borrow checker- prioritizes memory safety
    - Implements “result” and “option” for explicit error handling
    - Objective is to provide a memory safe version of C/C++
    - A lot of support from large companies, suited for complex high level tasks

  - Zig
    - Provides a lightweight error handling system by building it into the type system- “error unions”
    - Supports compile-time execution for optimal data structure generation and code optimization
    - Objective is to provide a modern C- gives user control of everything w/ minimal syntax and modern features
    - Very fast compilation times 
    - Ideal of embedded systems for its low level control

## Software -> Machine Code
- Interpreted 
  - Code is executed line by line w/ an interpreter at runtime 
  - Slower due to translation at runtime
  - Portable due to lack of platform-specific compilers
  - Ex: Python

- Compiled
  - Code is translated to machine code before execution
  - Faster due to translation before runtime
  - Less portable- requires recompilation for each target platform
  - Ex: C, C++, Java, Rust

- JIT
  - “Just-in-time” languages
  - Languages that both interpret at runtime and compile before runtime
  - Ex:
    - Java- first compiled to bytecode, then interpreted by JVM (“Java virtual machine”) or compiled to machine code by JIT compiler
    - C#, Kotlin, Visual Basic .NET, etc

## Common Tips
  - Never rely on implicit operation precedence
    - Add parenthesis per pair of operands to make operations explicit
    - Add spaces before and after all operators
    - Don’t add additional parenthesis around entire expressions

  - Avoid comments whenever possible- comments are software engineering failures
    - If they absolutely need to be written, make them clear/short/to the point
    - Add comments to explain **why** something is done

  - Avoid abbreviations unless it's definitely unambiguous in the scope of development
  - Add spaces between parenthesis and key words like if(), while(), etc

## SOLID Principles
  - Single responsibility principle
    - Every module should only have one reason to change

  - Open-closed principle
    - Code should be written for extension, but not modification
    - Changes to software should be made by adding new code, not by changing existing code

  - Liskov substitution principle
    - Everything should be interchangeable- write software to adhere to contracts to allow for easy substitution

  - Interface segregation principle
    - Avoid depending on things that aren’t used

  - Dependency inversion principle
    - High level application should not depend on low-level implementation details
    - Create modules wrapping low level details that are dependent on middle hardware interfaces instead

## NASA: The Power of 10
1.	Avoid complex flow constructs, such as goto and recursion.
2.	All loops must have fixed bounds. This prevents runaway code.
3.	Avoid heap memory allocation.
4.	~~Restrict functions to a single printed page.~~
    - Outdated- it should be “to a single concept that easily fits in your head”
5.	~~Use a minimum of two runtime assertions per function.~~
    - Outdated- we need a single assertion per unit test
6.	Restrict the scope of data to the smallest possible.
7.	Check the return value of all non-void functions, or cast to void to indicate the return value is useless.
8.	Use the preprocessor sparingly.
9.	Limit pointer use to a single dereference, and do not use function pointers.
    - Function pointers are good for abstractions, but otherwise no reason to use
10.	Compile with all possible warnings active; all warnings should then be addressed before release of the software.

## C
Foundational language introduced in 1970s by Bell Labs

Major C-based languages include:
  - C++
    - Extension of C w/ OOP, also by Bell Labs
  - C#
    - OOP language by Microsoft, heavily influenced by C++ and Java
  - Objective-C
    - Extension to C w/ Smalltalk-like OOP features for macOS and iOS development
  - SystemC
    - C++ based hardware modeling language used for PL design
  - Go
    - Syntactically inspired by C
    - Introduces garbage collection and concurrency primitives

### ANSI C
  - C programming language standardized by ANSI
  - In general we want to write code to follow ANSI C so that code is portable and compatible with all other C code

### C99 
  - Major revision in C programming language on top of ANSI C that introduced:

  - Single-line comments 
    - This is why we comment using /**/

  - Variable declarations in “for” loops
    - Aka variable declarations mixed w/ statements

  - Variable array lengths
    - Arrays can have sizes determined at runtime instead of compile time

  - Initialize specific members of struct/array
    - Designated initializer syntax allows this
    - Write functions to initialize structs instead, and use memset to init arrays

  - Complex numbers
    - For arithmetic operations

  - Bool data type
    - Use sparingly (as in, use it when you need the boolean true/false as opposed to needing some other binary data structure)

  - Stdint.h and inttypes.h
    - Critical issue w/ ANSI C
    - Would have to replicate stdint.h if this issue is encountered

  - Inline functions
    - This is a keyword to suggest the compiler to directly inject the function’s code into the caller’s code during compile time, instead of generating a separate function call 
    - A compiler can decide that the speed gained from injecting the function directly instead of creating a function call isn’t worth it, if the function is too large and takes up a lot of memory 
    - Use sparingly

  - Restrict keyword
    - Aka __restrict keyword in ANSI C
    - “Pointer qualifier” to indicate to the compiler that a pointer is the only reference to the object it points to (at least w/in the scope where the pointer is used)
    - Assumption that no other pointer will modify/access the same memory location allows the compiler to make optimizations 
    - Don’t use them

### C11 
  - Major revision in C programming language on top of C99 that introduced:
  
  - Atomic operations
    - Ensure that a set of operations are not interrupted by threads

  - Thread support library
    - Functions written for thread creation, joining, and synchronization

  - Static assertions
    - Validate certain conditions at compile time

  - Alignof and alignas
    - Alignof- Provides info about alignment requirement of datatype
    - Alignas- specifies alignment of variables

  - Noreturn attribute
    - Indicates that a function doesn’t return

  - Type _generic keyword
    - Allows selection of expression/statements based on type of expression?

  - Memory alignment functions
    - Functions to check dynamic memory allocation and checking alignment (“aligned_alloc” and “aligned_offset_malloc” respectively)

  - Unicode character literals
    - Can use Unicode chars in character and string literals

### Basic C Convention
- Data types
    - Stay consistent w/ datatypes
    - Use #include <stdint.h> to use explicit data types compatible w/ both 32 bit and 64 bit compilers
      - Don’t use int, long, etc on their own
        - They’re compiler dependent so their sizes will differ depending on the target platform
      - Choose datatypes wisely (and w/ respect to the processor you’re working with)
        - Using the target processor’s native data width allows for faster computation
        - A 32 bit processor will have an easier time working w/ 32 bit data, since the code translates to less assembly code due to lack of shifting necessary
        - Using native data types avoids gaps in memory

      - Use “char” only when handling strings

- Storage classes 
  - What determines the scope, lifetime, and linkage (whether variable/function can be accessed across translation tables) of variables and functions 
  - auto 	
    - default for local variables
    - limited to block it’s declared in, and lifetime ends after block exists

  - register
    - suggests to compiler to store variable in CPU register for fast access
    - not guaranteed for new compilers

  - static
    - local variables: 
      - lifetime does not end after exiting the block each time
      - data stored on data/bss segment instead of stack 

    - global variables / functions
      - scope is limited to the file
      - prevents use of extern
      - loophole is an accessor function that returns a pointer to the static variable casted to remove the static storage class- user can then modify the static variable in another source file via the pointer
      - make sure to avoid returning pointers to static variables/buffers by returning a copy instead, return by value if possible, or return a const for read-only

- extern
  - refers to variables/functions declared in another file/scope

- _Thread_local (C11)
  - Variable declared w/ thread-local storage duration
  - Every thread has an instance of the variable 

- Void*
  - Very flexible- can be used to point to anything in memory regardless of what the type of the data in the memory is

  - Caveat is that you can’t directly dereference a void*- you have to cast it first

  - Extra note: you can’t dereference a NULL pointer

  - So to make a C var act like a Python variable, you need to cast and allocate the pointer memory 

### Memory
  - Global and static variables are stored in the data segment (BSS uninitialized data segment or initialized data segment) on RAM, while local variables from function calls are stored on STACK on RAM
  - Const variables are stored on RAM (SRAM according to coding standards)
  - #define’s are replaced by the preprocessor before each source file is compiled, so it’s not stored anywhere- the replaced code is stored on flash together w/ the rest of the program

### Number type prefixes/suffixes
  - Lowercase prefix/suffix are easier to read

  - Integer suffixes:
    - u/U = unsigned int
    - l/L = long int
    - ll/LL = long long int
    - ul/UL = unsigned long int
    - ull/ULL = unsigned long long int
    - ex:
      - unsigned int thing = 3u;

  - Floating point suffixes:
    - f/F = float
    - l/L = long double
    - ex:
      - float floatThing = 3.14f;
      - #define FLOAT_THING 3.14F

  - Hexadecimal and Octal prefixes:
    - 0x/0X = hexadecimal literal
    - 0 = octal literal
    - ex:
      - Int octalThing = 035; //aka 29 in decimal

  - Complex suffixes (C99, so usually not relevant):
    - i/I = imaginary part of complex number
    - ex:
      - double complex thing = 1.0 + 2.0*I;

### Comparing variables to constants
  - Inject the constant first in the expression for a conditional statement:
  - If (0 != someVar) , if (0 == someVar) , etc
  - If the equality operator is mistyped and you have just a single equal sign in the expression, the compiler will throw an error if and only if you have the constant first
  - Is a decent idea, but w/ unit tests and readability as a priority, we don’t want to do this

### Const keyword
  - Prevents changing the value of a variable 
  - Good for read-only parameters, avoiding #defines if a constant is only needed in a particular scope, etc

  - Const w/ pointer
    - Const int* thing;
      - Prevents you from changing the value stored in the memory address

    - Int* const thing;
      - Prevents you from changing the address that the pointer points to

  - Loophole is created if you copy a pointer of a const variable to a pointer without the qualifier via casting and then try to modify the const value- leads to undefined behavior

### Implicit casting / integral promotion
  - Primitive data types are implicitly casted/promoted to larger types if comparisons, assignments, function calls are made w/ a smaller primitive data type than what’s expected
  - Need to be careful- there can be implicit casting from signed to unsigned if the unsigned data type is larger than the signed data type- NOT SAFE; causes implementation specific behavior

### Macros & Directives
  - Don’t use them at all
  - ... If a codebase already has macros:

    - Try to avoid defining new macros if there are macros that exist to do the same thing
    - No need to cast constants (macros) when using them if you’re careful w/ how you use them- but the issue is that there’s inherent room for misuse
    
    - If possible
      - Cast the constant in the macro definition directly if the constant’s use is constrained
        - #define MAX_SQUARE_WIDTH_CM (uint32_t)(18u)
      - Avoid parameterized macro functions
        - Funky w/ the way compilers deal w/ them
        - Use “inline” functions instead
          - Better yet just declare private static functions

    - \# symbol in the definition of a macro swaps out the #xx w/ a quoted string “xx”
      - #define print(thing) printf(#thing “ is a thing”) 
      - print(hi); -> printf(“hi” “ is a thing”);

    - \## symbol in macro definition allows for argument concatenation
      - #define combine(x, y) x ## y
      - combine(1, 23) -> 123
    
    - #if defined() vs #ifdef
      - #if defined() supports logical operators 
      - #ifdef is for when you’re checking for a single macro presence

    - #pragma
      - Provides compiler specific instructions to modify compiler behavior when compiling source code
      - Ex:
        - #pragma GCC diagnostic ignored “-Wpacked”

    - Suppresses packed related warnings (misaligned memory accesses, etc)
        - #pragma GCC diagnostic ignored “-Wattributes”
    - Suppresses attributes related warnings (unknown, ignored, misused attributes)

### Variables
  - Initialize all pointers and variable values to clarify what the function/code is working w/
  - Make all number unsigned where applicable

### Functions
  - Function parameters should have inputs only- output arguments aren’t intuitive
  - If a function modifies a value and has an output, return it
  - Don't repeat the same parameter checking logic everywhere- write code w/ TDD

  - Return values
    - Returning error code or status
      - Functions shouldn’t return status values- they should return what they say they return
      - Statuses add clutter, serve as depdendency magnets, and make functions unintuitive
      - Statuses shouldn’t be needed if a function follows SRP
      - If there’s error checking needed, there should be a function dedicated to error checking
  
    - Use “return” for functions, and “exit” for main

    - Don’t add return statements just because they quickly solve issues

    - ~~“return should be used in the function just once"~~
      - Outdated concept- if a function is short and follows SRP, then a small collection of return statements can easily fit in your head better than flow control to modify the value of a variable that’s returned

  - Parameters
    - ~~Function params should include p_in, p_out, p_inout when passing params that are modified in the function~~
      - This is "hungarian notation". It’s outdated- don’t do it
      - A function should clearly do one thing, w/ 3 or less parameters- there shouldn’t be a need to add complicated and implicit prefixes to function arguments

    - Passing a macro casted to a pointer (uint8_t* or whatever) for a parameter to a function that needs to be a pointer doesn’t allocate memory for the data and pass the address of the data as a pointer- it passes the data as if it was an address 
      - So if a macro assigned (64U) is casted to a pointer and passed to a function, then the pointer’s value will be 64U with some arbitrary value that it points to
        - Returns garbage if a function is supposed to return something, but doesn’t
        - A nice compiler would complain

### Avoid weird memory bugs
  - Explicitly cast to larger data types first to avoid overflow
  - Avoid large stack variables- use "static" keyword to store variables on RAM
  - Heap/data segments are used by all parts of the application, and each thread has its own stack

- Volatile
  - Used to tell the compiler that a variable can change unexpectedly- prevents optimization of variable access to ensure that all read/write is done by directly reading memory where the variable is stored
  - Using volatile on all variables leads to slow and inefficient code
  - Used when handling
    - Memory mapped peripheral registers
      - Register values are dependent and change w/ hardware, so variables that reference them should be “volatile”

    - Global variables modified in ISRs
      - Should also be “volatile” for the code to know that variables should be accessed directly from memory in case they’re updated in ISRs

    - Global vars accessed by multiple threads 
      - If an OS is used and multiple tasks access particular global vars, they should be declared “volatile” so variable changes are reflected on all threads

  - Loophole is created if you copy a pointer to a volatile variable to a pointer without the qualifier via casting- this defeats the purpose of the volatile qualifier and lets the compiler cache the variable to CPU registers preventing up-to-date accesses of the variable in memory

  - A user might cast to volatile if they’re dealing w/ pointers that are volatile- assignment to a volatile pointer requires the address being assigned to also be volatile

  - A volatile struct variable ensures that all accesses to the struct members are done with individual accesses to memory instead of using CPU registers, but the elements themselves aren’t volatile unless declared so

### Pointers, pass by reference vs value
  - & is used to get the address of data, and * is used to dereference data (to get the raw data from an address or pointer)
  - &arrayName[0], arrayName, &arrayName are all the same- they’re both addresses to the first element in an array
  - Pointer declaration asterisk (*)
  - Putting it on the datatype is nice to clarify that a variable is a pointer
      - Putting it on the variable name is nice when in need of multiple pointer declarations per line
      - Int *p, *thing, *otherThing;
      - Int *p, thing; <- "thing" isn’t a pointer


### Extern
  - Don’t use it
  - … If a codebase is already using it:

    - Changes the linkage of the function or variable, so link the function/variable outside of the file when it’s defined in another different file

    - Extern is used in files that don’t actually declare the variable, but instead declare the variable as a variable that’s declared somewhere else

    - Arrays and pointers
      - If you declare a pointer var (int *arr_ptr) then it’s valid to extern it in another file IF AND ONLY IF the pointer is initialized in the same statement properly
      - If the pointer isn’t initialized, then the array that’s externed will have undefined behavior (like pointing to some random place in memory)

### SizeOf()
  - Using sizeof will tell you how many bytes is allocated to a particular piece of reference

  - Size_t const TOTAL_ELEMENTS = (sizeof array) / (sizeof array[0])

    - This is bad practice, since array elements don’t have to be constrained to indices (elements could be less than a byte to have all elements next to each other contiguously)

    - The size of a pointer isn’t the size of an entire array either- it’s just the memory allocated for the pointer to exist

    - The takeaway is that: sizeof provides the number of bytes allocated for a variable (whether it’s number of bytes allocated for a pointer, for a variable pointing to the first element in an array, or the entire array)

  - Using macros
    - #define TOTAL_ELEMENTS(a) (sizeof (a) sizeof (a)[0])
    - Bad practice put into macro form

  - Allocating memory
    - Struct someStruct *thing = malloc(sizeof *thing)
    - This is useful for struct malloc
    - Note: malloc returns void* which safely and implicitly casts to pointer of any type, so no need to cast return value of malloc
    - Malloc in a function to initialize a struct can be avoided by demanding a pointer to the struct instead to make the caller responsible for memory allocation 

  - Replicating sizeof behavior
    - A decent copy is:
      - #define MY_SIZEOF(type) ((size_t)(((char*)(&(type*)0[1])) – (char*)(&(type*)0[0])))
  - But this still fails if the null pointer indexing and arithmetic results in an invalid memory access 
  - Also fails when you pass it a variable instead of a type
  - It’s an irreplaceable compile time macro/operator- can’t implement it 

  - Struct
    - If you call sizeof() on a struct (not a pointer to a struct) you get the total number of bytes of the elements in the struct, but the tricky caveat is that:
      - Padding is added after each element in the struct to let the next element be on the right boundary
      - Padding is added after the entire struct to adhere to the boundary required by the largest element in the struct
    - Ex:
      - Struct { uint8_t thing; uint8_t thing2; };
        - Sizeof returns 2
    - Struct { uint8_t thing; uint32_t thing2; uint8_t thing3; };	
      - 1 byte for thing, + 3 bytes to let thing2 be on 32bit boundaries
      - 4 bytes for thing2
      - 1 byte for thing3, + 3 bytes to pad and adhere to the largest element’s boundaries (thing2’s 32bit boundaries)
      - = 12 bytes
    - To minimize all padding, declare attributes of a struct in descending order by data type width

### Structs
  - Data is stored into structs for easy manipulation 
  - Should not include pointers to buffers that are accessible outside of the struct
    - Should instead include copies and other independent data
      - You can initialize structs by using “thing = { 0 }”
      - You can declare structs without tags or typedefs too

  - could do: struct { ... } var1, var2; if a struct isn’t going to be reused
      - Can also initialize just a part of a struct w/ a curly brace enclosed list- the rest of the elements will be initialized to 0
      - Can’t add the struct itself as a member of a struct when defining a struct, but can add pointers to the struct

      - Array members in structs need to have their sizes declared

  - Dynamic array members are C99+
  - Bit fields
    - You can specify elements in a struct to be allocated a desired number of bits w/ a colon
    - Size of the struct is still determined by the boundary of the largest type in the struct, but the multiple of that largest type is determined by the total number of bits required by adding all elements of the struct

### Enum
  - Use enums in place of macro masks and constants
  - When not used w/ typedef:
    - Enum itself is not stored in memory
    - All enum [tag] variables created are treated as ints- undefined behavior when an enum variable is assigned a value that’s not enumerated
    - All instances of the enumeration are replaced at compile time, just like macros
    - Enumeration instances and enum variables are treated as a general int otherwise

### Union
  - Was meant to have an object take different forms
  - Allows declaration of multiple identifiers for the same object in a particular location in memory
  - Can only be initialized to an object w/ the union’s first member’s type 

### Memcpy, memset
  - Use memcpy to copy data from one piece of data to another when
  - Data types for variables conflict w/ one another
  - Buffer data needs to be copied to another buffer

### Pointer arithmetic
  - Valid pointer arithmetic:
    - addition/subtraction w/ integers, assignment to pointers of the same type, assigning comparing to zero (NULL)

  - invalid:
    - adding multiple pointers, multiplying/dividing/shifting/masking, adding double/float, assigning to pointers of a different type without a cast (void* is exception)

  - Increment/decrement
    - Incrementing/decrementing a pointer increments/decrements by the size of the pointer
    - Does NOT increment/decrement by the size of the entire data struct or array that the pointer is pointing to
      - Need to use sizeof() on a struct to do so

  - Comparisons
    - To compare pointer addresses using <, >, ==, etc the data types for each pointer must match
      - There’ll be a warning otherwise

    - You can cast one pointer to another pointer- it’ll be the same abstraction of an address 
    - Just need to be careful of the boundary that the pointers are aligned on
      - On 32-bit systems, a pointer is most likely 4 bytes (regardless of what the pointer is for)
      - On 64-bit systems, a pointer is most likely 8 bytes

  - You can’t perform pointer arithmetic on function pointers
    - Location of function definitions is defined by the compiler- function definitions aren’t necessarily sequential 
    - You can’t get the size of a function by using pointer arithmetic

### Printf and ellipsis
  - Ellipsis 
    - The "…" param allows print to take as many variables as needed to fill in the string 
    - Wrapping Printf requires a dependency to va_list class- don't wrap printf it's a standard library function

  - Format specifiers
    - Used for printing, scanning, etc

  - Escape sequences 
    - All special sequences to be used when printing, etc

### Order of operator precedence
  - Don't memorize it and write tricky code
  - ... If you're looking at code that's depedent on precedence:
    - Unary, ternary, and assignments are evaluated right to left, but everything else is left to right

    - Order in which arguments of a function are evaluated isn’t defined by C

    - Comma operator
      - Evaluates from left to right, where the final value is the value of the rightmost expression 
      - Comma used to declare multiple variables in a single line is not a comma operator (order of evaluation isn’t defined)

### Assignment operator
  - Assignment statement is an expression too- it evaluates to the value assigned 
  - That’s why this is legal: int x = y = z = 6; (but bad practice)

### Jump statements
  - break, return, continue, goto
  - Use them sparingly (provided you're writing short functions)
    - Continue 
      - Exclusive to iterator tokens
      - Can’t be used for switch-case, etc
    - Goto
      - Forbidden
      - Was intended to exit out of loops and return a value when there’s more than one layer of nesting- an alternative to using multiple break statements

### Arrays
  - The confusion is when we need to declare array size and when we don’t
  - Provided we’re working w/ ANSI C for good practice and compatibility:
    - Not needed
      - Declaration w/ a string literal or initializer list
      - First size of multidimensional array when initialized w/ an initializer list
        - You still need the size if there’s no init value for the compiler to use to infer size
    - Needed
      - Declaring arrays without init value
    
  - Function arguments
    - Arrays passed to functions decay to pointers
    - An array size specified in a function signature doesn’t do anything… it’s just there for documentation purposes 
    - A multidimensional array passed to a function requires the second dimension and on to be specified in the function signature 
      - On the contrary, there’s also no way to force a user to pass a multidimensional array of a specific 1st dimension
    - A function that takes a pointer can take an array and vice versa
      - The only exception is multidimensional arrays- if a function’s signature demands a multidimensional array, then items passed to the function must have that demanded fixed second and on dimensions 

  - Pointer to a multidimensional array
    - This is the same as void function(int arr[][5])
    - You can keep stacking numbers in the signature in both the pointer and non-pointer versions
    - The pointer version is powerful since it can point to whatever it wants, and you can have each pointer point to arrays of varying sizes
  - Negative indices
    - Mm no you can’t array index like Python
    - But the issue is that if the negative index (space in memory before the 0th element in an array) happens to be valid, you won’t see the issue

### Strings
  - Compiler concatenation 
    - All adjacent strings are automatically concatenated:
    - printf("part of a sentence" "rest of the sentence");
    - char string[] = "part of a string" "rest of the string";

  - Another quirk is that string literals (naked strings) are stored in read-only memory, so they act as valid addresses
    - char *var1 = “some string” is valid, but only because the string literal is stored in read-only memory and it’s equivalent to an address for var1 to point to 
    - modifying the string values cause undefined behavior

  - integer arrays, etc aren’t stored in read-only memory, so this is invalid: int *var2 = { 1, 2, 3 };

### Breaking long lines
  - confusion lies when you do/don’t need the escape slash
    
    - do need slash:
      - Multi-line macros
      - Breaking other preprocessor definitions and expressions
      - Statements that don’t end w/ an operator at the end
        - …if possible break down long statements, but otherwise use escape characters over putting operators at the end of lines

    - don’t need slash:
      - adjacent string
        - again, compiler automatically concatenates strings

      - list of arguments in a function definition or call
        - usually, things enclosed in parentheses and braces don’t need escapes

      - Statements when they end w/ an operator
        - This doesn’t work w/o the operator at the end of the line to signal to the compiler that there are more operands on the next line
        - This makes the next line difficult to read, so USE ESCAPE

      - Array, struct, union initializer list
      - Statements surrounded w/ parenthesis
        - Awkward to add extra parenthesis if they’re not needed other than to break down the long line, so either break down the statement or use escape character

### \_\_attribute\_\_
  - “Compiler extension” / keyword to specify special properties for functions, variables, structures, types

  - Function attributes
    - void fatal_error() \_\_attribute\_\_((noreturn)); 
      - indicates that the function never returns

    - void log_message(const char *fmt, …) \_\_attribute\_\_((format(printf, 1, 2)));
      - checks for whether log_message follows printf-style formatting rules

  - Variable attributes
    - int my_var \_\_attribute\_\_((aligned(16)));
      - specifies memory alignment for variable

  - Typedef attributes
    - Struct \_\_attribute\_\_((packed)) PackedStruct { char a; char b; };
      - Removes padding in structs

  -	Exhaustive list:
    
    - Function attributes
      - noreturn
        - indicates that function never returns

      - deprecated
        - issues a warning if function is used

      - format(printf, x, y)
        - checks for printf-style format specifiers for correctness

      - always_inline
        - forces compiler to inline a function

      - noinline
        - prevents compiler from inlining a function

      - cold
        - optimizes function for infrequent execution (error handling, etc)

      - hot
        - optimizes function for frequent execution

      - pure
        - declares that a function doesn’t modify global state (no side effects)
        - no modifying global/static variables, no IO operations, always same output for the same input regardless of changes in global state

      - const
        - declares that function has no side effects (only depends on input arguments)

      - malloc
        - declares that function returns pointer to newly allocated memory

      - aligned(x)
        - specifies function alignment in memory

      - visibility(“hidden”)
        - controls symbol visibility
        - good for shared libraries

      - section(“name”)
        - places function in specific section of binary

      - constructor
        - marks function to run before main()

      - destructor
        - marks function to run after main() or exit()

      - weak
        - declares weakly linked function 

      - alias(“other_function”)
        - creates an alias for another function 

      - used
        - prevents compiler from removing function definition even if the function isn’t used

    - Variable attributes

      - aligned(x)
        - ensures variable is aligned to at least x bytes

      - packed
        - prevents padding in structures

      - deprecated
        - issues warning if variable is used

      - unused
        - prevents warning if variable is declared but not used

      - weak
        - declares weakly linked variable

      - section(“name”)
        - places variable in specific memory location

      - visibility(“hidden”)
        - hides symbol from shared libraries

      - tls_model(“model”)
        - specifies TLS (“thread local storage”) model

      - used
        - prevents compiler from removing variable even if the variable isn’t used
    
    - Typedef attributes
      - packed
        - removes padding in structures

      - aligned(x)
        - ensures a type is aligned to at least x bytes

      - transparent_union
        - allows automatic type conversion for union elements

      - deprecated
        - issues a warning if type is used

      - may_alias
        - prevents aliasing issues in strict aliasing mode

      - warn_unused_result
        - issues warning if function return value is ignored

### Errors
  - types include
    - compiler error
    - linker error
    - runtime error
    - warnings
    - logical error
    - preprocessor error
    - build system error

## Python
### Comments
  - Block comments written w/ docstrings, single-line comments written w/ “#”

### Constants
  - Constants are differentiated from global variables w/ capitalization where all caps = constant, but they’re all essentially global variables

### HEX integers
  - Python supports 0x for HEX representation

### Default parameters
  - When creating a new instance of a class, all parameters indicated in the signature of the constructor definition must be provided UNLESS the parameters have default values 

  - This serves as a shorthand way of implementing “overloading” concept as well, but there’s a catch when you assign default values to mutable parameters (noted below in “memory optimization in Python”)

### Memory optimization in Python
  - Python’s memory optimization is great for efficient memory allocation and reuse for mutable data
  - Side effects include all instances of a class sharing the same mutable variable when a mutable variable is declared and assigned in the signature of a method
  - The solution to this is to assign mutable variables “None”, an immutable singleton object (the singleton class is for when there should only ever be a single instance of said class)

### Useful features in C lacking in Python
  - Private vs public
    - Functions can’t be specified as private for file scope only
    - You either import an entire file, a module in a file, or nothing
    - Can’t import a file without also importing all the global functions 

  - Function prototypes
    - Doesn’t exist

  - Explicit integer data types
    - Doesn’t exist unless you import a library

  - Data type specification at function declaration
    - Doesn’t exist, but you can add “type hints” that help the user see what data types each variable is supposed to be
    - Annoying for functions that return multiple data
 
### PEP 8
  - “Python enhancement proposal”
  - A style guide for writing readable and consistent Python code, including:
    - Indentation
      - 4 spaces per indentation

    - Max line length
      - 79 char limit
      - Additional 72 char limit for comments/docstrings

    - Blank lines
      - 2 blank lines between functions (not in class) and classes, 
      - 1 blank line between methods in a class

    - Imports
      - Top of the file in order of:
        - Standard library imports
        - Related third-party imports
        - Local app/library-specific imports

    - Whitespace in expressions & statements
      - Avoid unnecessary spaces in parenthesis, brackets, braces
      - Don’t use spaces when indicating keywords or default values
    - Comments
      - Explain why things are done, not what’s done
      - Write in complete sentences
      - Put a space after “#” for the comment

    - Naming conventions
      - Function names, variable names, file names should be snake case (all lower)
      - Class names should be camel case (start w/ upper)
      - Constants are all upper w/ underscores
    
    - Docstrings
      - Should describe purpose of functions, classes, and modules
      - Eh just follow sphinx lol

    - Comparisons
      - Use “is” or “is not” when comparing “None” or Boolean values

## C++
  -	Asio library
    - Asynchronous IO via events
    - Part of the Boost C++ library
    - Low level IO library for C++

  - Embedded C++ vs C
    - C++
      - Object oriented concepts allow for better reusability and maintainability 
      - Adds overhead at runtime and on memory

    - C
      - Minal overhead, supported for all embedded systems
      - Harder to maintain w/ limited abstraction 

  -	C++ revisions 
    - C++98
      - Standardized the language w/ templates, exceptions, STL (“standard template library”)
    
    - C++03
      - Bug fix release for C++98
    
    - C++11
      - Smart pointers, auto, nullptr, lambda functions, move semantics, range-based for, multithreading support

    - C++14
      - Generic lambdas, relaxed constexpr

    - C++17
      - Std::optional, structured binding, and if constexpr

    - C++20
      - Concepts, coroutines, ranges, modules

    - C++23
      - Bug fixes, usability improvements, better library support

## Others
add new items here