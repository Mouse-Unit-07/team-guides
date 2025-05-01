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

### Other C releases
- **K & R C**
  - First edition in 1972
  - Second edition in 1978
- **C90**
  - International adoption of ANSI C
  - Minor corrections
- **C95**
  - Amendment to C90- wchar_t, wide characters, diagraphs, some library additions
- **C17, sometimes called C18**
  - Bugfixes/clarifications to C11
  - No major new features
- **C23**
  - Added nullptr keyword like C++
  - New safer string functions
  - More modern usability improvements
- **w/ respect to gcc**
  - gcc 3.x
    - supports C90
  - gcc 4.x, gcc 5.x
    - supports C99 and basic C11
  - gcc 8.x
    - full C11 support and C17
  - gcc 13.x+
    - starts to implement C23

### C Standard Library
- C standard library implementations vary w/ compiler (gcc (MinGW for Windows), clang, MSVC (Microsoft visual C++), ARM gcc toolchain, etc) and use different C library implementations, and by the compiler version and the version of C supported
- C standard libraries:
  - glibc
    - GNU systems (Linux)
  - musl
    - lighweight libc for static linking / embedded Linux
  - newlib
    - lightweight libc for embedded systems (ARM MCUs, etc)
  - uclibc
    - small C library for embedded Linux systems
  - Microsoft CRT
    - “C runtime”
    - C library on Windows
- Library headers
  - **K&R C (1972/1978)**
    - no formal standard library
    - stdio.h, ctype.h existed informally
  - **ANSI C / C89 / C90**
    - <assert.h>
      - Diagnostics- catch programming errors early during development and debugging
      - assert()
        - checks an expression at runtime
      - NDEBUG
        - Preprocessor macro- disables assert() if NDEBUG is defined before assert.h
    - <ctype.h>
      - Character classification- functions for checking characters and case conversion
      - Critical items
        - isalnum(int c)
          - check for alphanumeric (letter or digit)
        - isalpha(int c)
          - check for alpha
        - isdigit(int c)
          - check for decimal digit (0-9)
        - islower(int c)
          - check if lowercase
        - isupper(int c)
          - check if uppercase
        - isspace(int c)
          - check if whitespace character (space, tab, newline, etc)
        - ispunct(int c)
          - check if punctuation character
        - isxdigit(int c)
          - check if hexadecimal digit (0-9, a-f, A-F)
        - isprint(int c)
          - check if printable character including spaces
        - isgraph(int c)
          - check if printable, but not a space
        - iscntrl(int c)
          - check if control character (\n, \r, etc)
        - tolower(int c)
          - convert to lowercase if uppercase
        - toupper(int c)
          - convert to uppercase if lowercase
    - <errorno.h>
      - …C tried to standardize exceptions, before the concept matured…
      - Error codes- standard way for functions to report error conditions without needing to change return type
      - Sets global variable errno and has functions return special values like -1, NULL, etc to indicate what an error was, as opposed to functions returning error objects
      - Critical items
        - errno
          - global or thread local integer variable that stores error code of error producing function call
        - error macros
          - symbolic names for error codes
          - EINVAL = invalid argument
          - EIO = input/output error, etc
    - <float.h>
      - Floating-point limits- provide limits and characteristics of floating-point types as constants defined at compile time
      - Critical items
        - Min/max values
          - FLT_MAX, DBL_MIN
          - Largest and smallest normalized positive values
        - Precision
          - FLT_DIG, DBL_DIG
          - Minimum number of decimal digits that can be stored without loss
        - Machine epsilon
          - FLT_EPSILON, DBL_EPSILON
          - Smallest positive number e such that 1.0 + e != 1.0
        - Exponent range
          - FLT_MIN_EXP, DBL_MAX_EXP
          - Range of exponent values
        - Radix/rounding
          - FLT_RADIX, FLT_ROUNDS
          - Info about the number base (usually 2) and rounding behavior
    - <limits.h>
      - Integer limits- define implementation-specific limits for integer types in C (max/min values, number of bits occupied, whether char is signed or unsigned by default)
      - Wraps compiler specific macros like \_\_INT_MAX\_\_
      - Critical components
        - INT_MIN, LONG_MIN
          - Smallest representable (most negative) value
        - INT_MAX, ULONG_MAX
          - Largest representable value
        - CHAR_BIT
          - Number of bits in a byte
        - SCHAR_MIN, SCHAR_MAX
          - Range of signed char
        - UCHAR_MAX, UINT_MAX
          - Largest values for unsigned types
    - <locale.h>
      - Localization
        - “Locale”- a set of cultural preferences that affect the behavior of certain functions in C like string comparison, number formatting, date/time formatting, etc
      - Ex: decimal point vs comma, etc
    - <math.h>
      - Mathematics functions- definitions and mathematical functions
      - Basic arithmetic 
        - fabs(x)
          - absolute value of floating point
      - Exponentiation and logarithmic
        - pow(x, y)
        - sqrt(x)
        - log(x)
          - natural log, ln(x), base e
        - log10(x)
      - Trigonometric
        - sin(x), cos(x), tan(x), asin(x), acos(x), atan(x)
          - all in radians
      - Hyperbolic
        - sinh(x), cosh(x), tanh(x)
      - Rounding
        - ceil(x), floor(x)
          - smallest/largest integer greater/less than or equal to x
      - constants
        - NAN
          - Represents “not a number”
          - Used for operations that can’t produce a valid number- 0/0, etc
    - <setjmp.h>
      - Oh man
      - Non-local jumps- for storing and restoring execution state, while avoiding use of goto
      - Purpose is identical to purpose of goto- to handle errors in deeply nested code
    - <signal.h>
      - Signals- for asynchronous communication for processes to know that an event occurred 
      - signal(int signum, sighandler_t handler)
        - installs a signal handler 
      - predefined signals
        - SIGINT
          - Interrupt signal- ctrl + c
        - SIGTERM
          - Termination signal
        - SIGKILL
          - Immediate process termination signal
        - SIGSEGV
          - Segmentation fault
          - Aha this is how an IDE can identify when invalid memory accesses are made at runtime
        - SIGFPE
          - Floating point exception 
          - Division by 0, etc
        - SIGABRT
          - Abort signal- abort() call 
        - SIGILL
          - Illegal instruction signal 
      - Signal handling safety
        - You need to make sure you’re using asynchronous signal-safe functions in signal handlers like exit(), _exit(), write(), signal()
    - <stdarg.h>
      - Variable arguments- working w/ functions that take a list of arguments- aka definition file for va_list
      - Critical items
        - va_list
          - type to hold the argument list state
        - va_start
          - initializes va_list for processing arguments
        - va_arg
          - retrieves next argument in a list
        - va_end
          - cleans up va_list
        - va_copy
          - copies state of va_list to another variable
    - <stddef.h>
      - Header that’s usually included in other C standard library headers
      - Critical typedefs and macros
    - <stdio.h>
      - Input/output- functions and macros to handle IO operations- reading/writing to files, standard IO streams, interacting w/ devices, etc
      - Critical items
        - File operations
          - fopen(), fclose(), fread(), fwrite(), fseek(), ftell()
        - Formatted input/output
          - printf(), scanf()
          - fprintf(), fscanf()
      - writes and reads from a specified file
          - sprintf(), sscanf()
      - writes and reads to a buffer/string 
        - Character input/output
          - getchar(), putchar()
          - getch(), putch()
      - some implementations support these functions to read/write without buffering
        - End-of-file handling
          - EOF- constant indicating the end of a file, or error in IO operations
        - Buffered IO operations
          - setbuf(), setvbuf(), fflush()
        - Standard IO streams
          - stdin, stdout, stderr
          - standard streams for input, output, and error output
          - predefined file pointers in C- points to console’s input and output
        - Error handling
          - perror(), clearerr(), feof(), ferror()
        - Temporary files
          - tmpfile(), tmpnam()
        - File control
          - remove(), rename()
    - <stdlib.h>
      - “General utilities”
        - Memory allocation
        - Process control
        - Conversion of data types
        - Random number generation
        - Environment management
      - Critical items
        - Memory management
          - malloc(), calloc(), realloc() free()
        - Process control
          - exit()
      - terminates the program w/ specified exit status
          - abort(), atexit(), system()
        - Conversion functions
          - atoi()
      - string (ascii) to integer
          - atol()
      - string to long integer
          - atoll()
      - string to a long long integer
          - strtol()
      - string to a long integer w/ error checking for invalid input
          - strtoul()
      - string to an unsigned long integer
          - strtod()
      - string to a double-precision floating-point number
        - Random number generation
          - rand(), srand()
        - Environment management
          - getenv()
      - retrieves value of environment variable
          - putenv()
      - sets/modifies value of environment variable
        - Other utility functions
          - These are math related, but exist here as general utilities since they don’t involve complex math
          - abs(), labs(), llabs()
      - absolute value of integer, long, long long
          - div(), ldiv(), lldiv()
      - computes quotient and remainder of int, long, long long 
    - <string.h>
      - String handling- performing string operations
      - Critical items
        - strlen()
          - returns length of null-terminated string
        - strcpy() strncpy()
          - copies null-terminated string, w/o and w/ specified number of characters
        - strcat() strncat()
          - concatenates null-terminated string to another w/o and w/ specified number of characters
        - strcmp() strncmp()
          - compares two null-terminated strings w/o and w/ specified number of characters 
        - strchr() strrchr()
          - locates first and last occurrence of a character in a string respectively 
        - strstr()
          - locates first occurrence of a substring in a string
        - memcpy() memmove() memset() memcmp() 
          - good to know that these functions exist here instead of in general utilities
        - strtok()
          - breaks string into sequence of tokens based on delimitters
    - <time.h>
      - Date and time- measuring intervals, manipulating/formatting time, ettc
      - Critical items
        - time(), clock(), difftime(), mktime(), localtime(), gmtime(), strftime(), asctime(), ctime()
          - various time related functions…
        - sleep()
          - oh man
          - suspends execution of the program for a specified number of seconds
        - struct tm
          - represent time components
          - sec, min, hour, day of the month, month, years since 1900, day of the week, day of the year, daylight saving time flag
          - CLOCKS_PER_SEC
      - Ticks per second
      - \_\_TIME\_\_, \_\_DATE\_\_
        - It’s weird, but this C standard header doesn’t provide wrappers for these compiler macros
        - These macros are compiler exclusive
        - C95
          - Old effort to try and integrate more character types into char type before Unicode took over
    - <wchar.h>
      - Wide character handling
    - <wctype.h>
        - Wide character classification
  - **C99**
    - Expanded on:
      - <math.h> expansion
        - Functions
          - fmod(x, y)
      - remainder of x/y as floating-point
          - round(x)
      - nearest integer to x
      - halfway cases rounded away from 0
          - fma(), fmax(), fmin(), fpow(), trunc(), ilogb(), scalbn(), nextafter(), rem(), copysign()
        - Constants
          - M_PI = pi
          - M_E = e
          - M_LN2 = Ln(2)
          - M_LN10 = Ln(10)
          - M_LOG2E = Base 2 log of e
          - HUGE_VAL
            - Constant representation of +infinity for floating types
      - <stdio.h> expansion
        - Functions
          - snprintf()
            - sprint(), but limits number of characters that can be written
          - vsprintf()
            - snprintf() that takes variable number of arguments
          - vscanf(), vfscanf(), vsscanf()
            - variable list of arguments for input operations
          - New format specifiers
            - %a
              - Printing/scanning floating-point numbers in hex
            - %z
              - Printing size_t values
            - %ll
              - Printing long long types
      - <stdlib.h> expansion
        - aligned_alloc()
          - allocates memory w/ specified alignment 
        - calloc()
          - existed before C99, but only in C99 it’s been clarified that it allocates and zeros memory
        - atof(), atoi(), atoll() and variations
          - further standardized to convert strings into various types
        - rand(), srand() expanded
        - strtol(), strtoll(), stroul(), strtoull()
          - functions for string to number conversion
        - Sorting and searching
          - qsort()
            - generic quick sort implementation
          - bsearch()
            - generic binary search implementation
    - <complex.h>
        - Complex number arithmetic (imaginary numbers)
    - <fenv.h>
      - Floating-point environment- provides exceptions and rounding modes
      - FE_TONEAEREST, FE_UPWARD, FE_DOWNWARD, FE_TOWARDZERO, etc
    - <stdint.h>
      - Fixed-width integer types
      - uint8_t, etc that we know and love
    - <inttypes.h>
      - Extension to stdint.h providing macros for formatting and printing fixed-width integer types defined in stdint.h
      - Format macros
        - PRId8, RPIu8, PRIx8, etc
        - So format specifies for each width-specific integer type
      - Integer type limits
        - INT8_MIN, INT32_MIN, etc
      - Macros for integer type size checking
        - INT8_WIDTH, UINT16_WIDTH, etc
    - <stdbool.h>
      - Boolean types
      - “bool” type, “true”, “false”
    - <tgmath.h>
      - (exists in C99, but deprecated in C11)
      - Attempted to implement type generic math
  - **C11**
    - Expansions
      - Added static_assert, anonymous structs/unions
    - <stdalign.h>
      - Provides macros and facilities for type alignment requirements in C
    - <stdatomic.h>
      - Atomic operations
    - <threads.h>
      - Multi-threading
    - <uchar.h>
      - Unicode character types
  - **C17 / C18**
    - No new headers
    - Just bugfix/clarification release
  - **C23**
    - Expansions
      - <string.h>
      - Enhanced functions
        - <stdio.h>, <stdlib.h>, <assert.h>, etc
    - <stdckdint.h>
      - Checked integer arithmetic

### Compiler Defined Constants / Functions
- **Macros**
  - General macros
    - \_\_TIME\_\_
      - time of compilation
    - \_\_DATE\_\_
      - Date of compilation 
    - \_\_FILE\_\_
      - Name of current source file
    - \_\_LINE\_\_
      - Current line number in source file
    - \_\_STDC\_\_
      - 1 if the compiler conforms to ANSI C standard
  - Preprocessor conditionals and versioning
    - \_\_cplusplus
      - Defined if code is being compiled as C++ code
    - \_\_STDC_VERSION\_\_
      - Defined if compiler supports standard C
    - \_\_GNUC\_\_, \_\_GNUC_MINOR\_\_, \_\_GNUC_PATCHLEVEL\_\_
      - Indicate version of GCC being used 
    - \_\_clang\_\_
      - Defined when Clang is being used
    - \_\_MINGW32\_\_
      - Defined when MinGW is being used
  - Architecture-specific macros
    - \_\_x86_64\_\_, \_\_amd64\_\_
      - Defined when compiling for 64-bit x86 architecture
    - \_\_i386\_\_, i686\_\_
      - Defined when compiling for 32-bit x86 architecture
    - \_\_arm\_\_, \_\_aarch64\_\_
      - Defined when compiling for ARM architecture
    - \_\_mips\_\_
      - Defined when compiling for MIPS architecture
    - \_\_powerpc\_\_, \_\_ppc\_\_
      - Defined when compiling for PowerPC architecture 
  - Platform-specific macros
    - \_\_WIN32\_\_, _WIN32
      - Defined when compiling for Windows platforms
    - \_\_APPLE\_\_
      - Defined when compiling on macOS
    - \_\_linux\_\_
      - Defined when compiling for Linux platforms
    - \_\_unix\_\_
      - Defined when compiling on any Unix-like platforms
    - \_\_ANDROID\_\_
      - Defined when compiling for Android platforms
  - Optimization macros
    - \_\_OPTIMIZE\_\_
      - Defined if compiler is performing optimizations
    - \_\_NO_INLINE\_\_
      - Defined if function inlining is disabled by the compiler
    - \_\_INLINE\_\_
      - Defined if function inlining is enabled
  - Memory related macros
    - \_\_near, \_\_far, \_\_restrict
      - Used in 16-bit compilers to specific near/far memory models for pointers
- **Functions**
  - \_\_builtin functions
    - Provided by GCC/Clang compilers for performance/optimization purposes


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
- **compiler error**
  - expected ‘;’ before
    - missing semicolon
  - undeclared identifier
    - variable or function not defined
  - incompatible types 
    - assignment of wrong type
  - redefinition
    - variable or function defined more than once
  - conflicting types 
    - function prototype doesn’t match implementation
  - invalid operands
    - performing an operation on incompatible types
  - non-void function should return a value
    - return missing in non-void function
  - array subscript is not an integer
    - using a non-integer index
  - initializer element is not constant
    - invalid static/global variable initialization 
  - storage size of ‘X’ isn’t known
    - incomplete type used
  - too few/many arguments to function
    - function call mismatch
  - dereferencing pointer to incomplete type
    - missing struct/typedef definition
- **linker error**
  - undefined reference to ‘function’
    - function declared but not defined
  - multiple definition of 
    - function or variable defined in multiple source files
  - cannot find -l<libname>
    - missing library during linking
  - unresolved external symbol
    - object file references missing symbol
  - symbol already defined in object
    - conflicting symbol definitions
  - duplicate symbol
    - identical symbols in separate files
- **runtime error**
  - segmentation fault (SIGSEGV)
    - invalid memory access
  - bus error
    - misaligned memory access
  - stack overflow
    - infinite recursion or large stack allocation
  - division by zero
    - dividing integer or float by 0
  - null pointer dereference
    - dereferencing a NULL pointer
  - use-after-free
    - accessing freed memory
  - memory leak
    - allocated memory not freed
  - buffer overflow
    - writing past array boundaries
  - double free
    - freeing already freed memory
  - undefined behavior
    - from violating C spec (signed overflow, assigning a enumerated variable something that’s not enumerated, etc)
- **warnings**
  - unused variable/function
    - unused declaration
  - comparison between signed and unsigned 
    - type mismatch
  - control reaches end of non-void function
    - missing return
  - uninitialized variable
    - variable used without initialization
  - implicit declaration
    - function used without a prototype
  - cast from pointer to integer of different size
    - unsafe cast
  - ignoring return value
    - return value not used 
- **logical error**
  - wrong condition in if/while
    - = instead of ==, etc
  - infinite loop
    - missing exit condition
  - incorrect algorithm
    - wrong output due to logic flaw
  - off-by-one error
    - accessing one element too many/few
  - misuse of operators
    - misuse of operators
- **preprocessor error**
  - #include file not found
    - missing or misspelled header
  - #ifdeef/#ifndef mismatch
    - conditional compilation issues
  - macro redefined
    - duplicate macro definitions
  - unterminated #if
    - mismatched #if/#endif
  - #error directive
    - Manual compile-time error trigger
- **build system error**
  - no rule to make target
    - missing dependency file
  - missing separator
    - makefile syntax error
  - undefined CMake command
    - invalid or unknown command
  - cannot open source file
    - file path wrong or missing
  - cannot find compiler
    - misconfigured toolchain

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