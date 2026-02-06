# Team Rules

- This document outlines all development rules

## Index

- [Objective](#objective)
- [Can We Change Something?](#can-we-change-something)
- [Best Practices, New Toys](#best-practices-new-toys)
- [Key Books](#key-books)
- [Uniform Development Environment](#uniform-development-environment)
- [Development Practices](#development-practices)
- [Code](#code)

## Objective

- Build a cracked micromouse that zooms through a maze

## Can We Change Something?

- Everything is on the table for change (~~square up and duke it out~~ nah jk)
- If anything is painful, inefficient, not beneficial enough, etc, we can talk and make changes changes accordingly

## Best Practices, New Toys

- All tools in use described in [sketches/development-tools](https://github.com/Mouse-Unit-07/sketches/blob/main/development-tools/development-tools.md)
  - As a tiny team, we can get away w/ monoliths, sending each other files over chats, working without version control, etc if we wanted to
  - This endeavor also never ends- you're never doing anything the "best way"
- We just want to avoid:
  - Managing piles of zip files on Discord
  - Rewriting firmware w/ each hardware change
  - Asking each other about how something is implemented at the very last step when integrating together all project parts
  - Nightmare debugging after writing a lot of code
- With our newfound powers, we can:
  - Write working software as fast as possible
  - Write software that we can all quickly read and start tampering
  - Maximize parallel work and allow anyone to work on anything
  - Have no doubt in what we need to do
  - Implement everything on the micromouse todo list (and feel like we're using netherite weapons to take down spiders)

## Key Books

- TLDR for readings here: [fundamental-engineering-notes](https://github.com/Mouse-Unit-07/fundamental-engineering-notes/tree/main)
- As long as we have these down we're good to go:
  - _Clean Code_
  - _Test-Driven Development for Embedded C_
  - _Modern C++ Programming with Test-Driven Development: Code Better, Sleep Better_
  - _The DevOps Handbook_
  - _UML Distilled_
- Any team preferences that these books don't specify are mentioned below

## Uniform Development Environment

- [software-development-environment](https://github.com/Mouse-Unit-07/software-development-environment)
  - All build tools, unit testing, format checking, code analysis, etc in one place
  - Not as great as a Docker container, but does the job
- Examples of source code repos that are compatible w/ this environment are here:
  - [experiment-software-hello-world](https://github.com/Mouse-Unit-07/experiment-software-hello-world)
  - [experiment-software-repeat-hello-world](https://github.com/Mouse-Unit-07/experiment-software-repeat-hello-world)

## Development Practices

- Git
  - Guide here: [fundamental-engineering-notes/../using-git.md](https://github.com/Mouse-Unit-07/fundamental-engineering-notes/blob/main/markdown-notes/technical-essentials/dev-ops/tools/using-git.md)
  - No code reviews- we can talk if anything bothers us
    - We have clang-tidy, CppUCheck, TDD, and existing software repos- plenty for us to work on our own
  - Make branches for everything
  - Git Commits
    - Use conventional commit messages
    - Don't stockpile a collection of commits for a single pull-request
  - Follow source code templates
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

## Code

- 80 characters per line
  - Makes GitHub side-by-side view easy to see
- No tabs, 4 spaces per indentation
- Pointer asterisk on variable name, not data type
  - `uint32_t *myPointer = NULL;`
  - `uint32_t *myPointer, *anotherPointer, *lastPointer;`
  - Arbitrary, but useful if you were to declare multiple pointers in one line (which you shouldn't do either...)
- No single line function definitions
  - They're hard to catch and differentiate w/ other code
- No single line enumerations
  - A bit more arbitrary than function definitions
  - Avoids need to go back and forth between single line and multiple line format if changes were to be made
- Casing
  - Variables, functions, typedefs, structs, + classes
    - All snake case (all lowercase w/ underscores between: `just_like_this`)
    - It's easier to read than camel case, and common for embedded code
    - DON'T add `_t` suffix- that's reserved for code following POSIX like `size_t`
  - Constants
    - Screaming snake case (all caps w/ dashes between: `JUST_LIKE_THIS`)
- C++ (and any other OO language)
  - ...Original thought was to use camel/pascal case for OO languages, but it's a mess to look at CppUTests that mix C++ and C
  - Let's just follow C casing
- Java Docs
  - No Java Doc comment headers
  - We're not writing front facing API's, so we're not mandated to inject documentation in source code to generate nice Doxygen files
  - Less comments the better
- Curly Braces
  - Use curly braces even when there's only a single line to surround
    - There should always be less lines of code, but lack of braces causes hesitation to add / remove lines due to extra step of adding/removing braces
  - Open curly brace `{` on the same line as conditional statement, unless it's a function definition (or anything else that can't be nested)
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
