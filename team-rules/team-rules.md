# Team Rules

- This document outlines all development rules

## Index

- [Overview](#overview)
- [Key Books](#key-books)
- [Uniform Development Environment](#uniform-development-environment)
- [Development Practices](#development-practices)
- [Programming](#programming)
- [Can We Change Something?](#can-we-change-something)

## Overview

- **Objective**
  - Build a cracked micromouse that zooms through a maze
- **Do we need all these tools and infrastructure?**
  - As a tiny team, we can get away w/ monoliths, sending each other files over chats, working without version control, etc if we wanted to
  - ...But, we know that:
    - Managing piles of zip files on Discord is a pain
    - Firmware will need to be re-written each time hardware changes (it takes forever)
    - Asking each other about how something is implemented at the very last step when integrating together all project parts is a waste of time
    - Debugging after writing code is a nightmare, especially when multiple engineers wrote something together
  - ...There's no reason not to equip ourselves w/ modern know-how and tools that solve these issues
- **So, what're we doing?**
  - We will follow the bare minimum set of modern practices to:
    - Write working software as fast as possible
    - Write software that we can all quickly read and start tampering
    - Maximize parallel work and allow anyone to work on anything
    - Have no doubt in what we need to do
    - Implement everything on the micromouse todo list (and feel like we're using netherite weapons to take down spiders)
  - All tools described in [sketches/development-tools](https://github.com/Mouse-Unit-07/sketches/blob/main/development-tools/development-tools.md)

## Key Books

- Let's follow principles introduced in the below books:
  - _Clean Code_
  - _Test-Driven Development for Embedded C_
  - _Modern C++ Programming with Test-Driven Development: Code Better, Sleep Better_
  - _The DevOps Handbook_
  - _UML Distilled_
- Development schemes/decisions that don't have best/standard practices are specified in the rest of this document

## Uniform Development Environment

- Let's all develop using the same development environment to be on the same page w/ build tools, unit testing, format checking, code analysis, etc
- Our current implementation of a uniform development environment is this:
  - [software-development-environment](https://github.com/Mouse-Unit-07/software-development-environment)
- Examples of source code repos that are compatible w/ this environment are here:
  - [experiment-software-hello-world](https://github.com/Mouse-Unit-07/experiment-software-hello-world)
  - [experiment-software-repeat-hello-world](https://github.com/Mouse-Unit-07/experiment-software-repeat-hello-world)

## Development Practices

- No code reviews, but it's a free-for-all to write comments to nitpick
  - Comments must be resolved
- Don't directly push to main on Git repos
  - Again, no reviewing pull-requests, but isolates all development efforts and keeps main branch clean
- Branches should have short lives
  - As soon as a development branch is done, delete it
- Commits
  - Use conventional commit messages
  - Don't stockpile a collection of commits for a single pull-request
- Follow source code templates
  - Adhere to comment headers and code structure defined by source code templates
- Repo names
  - All lowercase, dashes between words
- Filenames, directory names
  - If source code file/folder name
    - **Snake case**- All lowercase and underscores between words
  - If not source code file/folder
    - **Kebab case**- dashes between words instead of underscores, and all lowercase
- Generate and share development items through GitHub Organization
  - No passing/storing stuff on Google Drive, Discord, etc
  - Store documentation you generate on GitHub Organization repo

## Programming

- 80 characters per line
  - Makes GitHub side-by-side view easy to see
- No tabs, 4 spaces per indentation
  - Arbitrary, but most IDE's/text editors default to 4 spaces
- Curly Braces
  - Use curly braces even when there's only a single line to surround
    - There should always be less lines of code, but lack of braces causes hesitation to add / remove lines due to extra step of adding/removing braces
  - Open curly brace `{` on the same line as conditional statement, unless it's a function definition
    - Lord Linus Torvald's Linux Kernel guide: https://docs.kernel.org/process/coding-style.html
    - You can't nest function definitions in C, so the highlight from `{` on its own line is nice
    - Otherwise, let's keep it compact
  - Keep closing curly brace `}` on its own line, except where it's followed by a continuation of the same statement
    - Also by Lord Linus Torvald
    - Ex:

```
do {
    /* body here */
} while (condition)

if (x == y) {
    /* ... */
} else if (x > y) {
    /* ... */
} else {
    /* ... */
}
```

- Pointer asterisk on variable name, not data type
  - `uint32_t *myPointer = NULL;`
  - `uint32_t *myPointer, *anotherPointer, *lastPointer;`
  - Arbitrary, but useful if you were to declare multiple pointers in one line (which you shouldn't do either...)
- No single line function definitions
  - They're hard to catch and differentiate w/ other code
- No single line enumerations
  - A bit more arbitrary than function definitions
  - Avoids need to go back and forth between single line and multiple line format if changes were to be made
- C
  - Variables, functions, typedefs, structs
    - All snake case (all lowercase w/ underscores between: `just_like_this`)
    - It's easier to read than camel case, and common for embedded code
    - DON'T add `_t` suffix- that's reserved for code following POSIX like `size_t`
  - Constants
    - Screaming snake case (all caps w/ dashes between: `JUST_LIKE_THIS`)
- C++ (and any other OO language)
  - Variables, functions
    - Camel case (first letter lowercase, and first letter of following words capitalized: `justLikeThis`)
  - Classes, structs
    - Pascal case (camel case, but first letter capitalized too: `JustLikeThis`)
  - Constants
    - Screaming snake case
- Java Docs
  - No Java Doc comment headers
  - We're not writing front facing API's, so we're not mandated to inject documentation in source code to generate nice Doxygen files
  - Less comments the better

## Can We Change Something?

- Everything is subject to change if we find anything painful, inefficient, etc
- We can ~~square up and duke it out~~ talk and make changes changes accordingly
