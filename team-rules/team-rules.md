# Team Rules
This document outlines all development rules.

## Objective
- Build a cracked micromouse that zooms through a maze

## Do We Really Need All These Tools?
- As a tiny team, probably not- we can get away w/ monoliths, sending each other files over chats, working without version control, etc if we wanted to

- ...But, provided we know that
  - managing piles of zip files on Discord is a pain
  - firmware will need to be re-written each time hardware changes (it takes forever)
  - asking each other about how something is implemented at the very last step when integrating together all project parts is a waste of time
  - debugging after writing code is a nightmare, especially when multiple engineers wrote something together
- ...There's no reason not to equip ourselves w/ modern know-how and tools that solve these issues

## Aight, So What're We Doing?
- We will follow the bare minimum set of modern practices to:
  - Write working software as fast as possible
  - Write software that we can all quickly read and start tampering
  - Maximize parallel work and allow anyone to work on anything
  - Have no doubt in what we need to do
  - Implement everything on the Micromouse todo-list and feel like we have netherite weapons to take down a spider
- All tools described in [engineering-sketches/development-tools](https://github.com/Mouse-Unit-07/engineering-sketches/blob/main/development-tools/development-tools.md)

## Rules

### Read & Follow Key Books
- Let's follow principles introduced in the below books:
    - *Clean Code*
    - *Test-Driven Development for Embedded C*
    - *Modern C++ Programming with Test-Driven Development: Code Better, Sleep Better*
    - *The DevOps Handbook*
    - *UML Distilled*
- TLDR notes provided in [team-guides/key-readings/tldr-notes](https://github.com/Mouse-Unit-07/team-guides/tree/main/key-readings/tldr-notes)
- Below are things not specified in these books

### Development Practices
- No code reviews, but it's a free-for-all to write comments to nitpick
  - Comments must be resolved
- Don't directly push to main on Git repos
  - Again, no reviewing pull-requests, but isolates all development efforts and keeps main branch clean
- Branches should have short lives
  - As soon as a development branch is done, delete it
- Commits
  - Check out [team-guides/guides/tools/git-guide](https://github.com/Mouse-Unit-07/team-guides/tree/main/guides/tools/git-guide)
  - Use conventional commits
  - Don't stockpile a collection of commits for a single pull-request
- Follow source code templates
  - Adhere to comment headers and code structure defined by source code templates: [team-guides/source-templates](https://github.com/Mouse-Unit-07/team-guides/tree/main/source-templates/c-template)
- Repo names
  - All lowercase, dashes between words
- Filenames, directory names 
  - If source code file/folder name
    - **Snake case**
      - All lowercase
      - Underscores between words
  - If not souce code file/folder
    - Snake case, but dashes between words instead of underscores
   if it's source files/folders
- Generate and share development items through GitHub Organization
  - No passing/storing stuff on Google Drive, Discord, etc
  - Store documentation you generate on GitHub Organization repo

### Programming
- 80 characters per line
  - Makes GitHub side-by-side view easy to see
- No tabs, 4 spaces per indentation
  - Arbitrary, but most IDE's/text editors default to 4 spaces
- Curly Braces
  - Use curly braces even when there's only a single line to surround
    - there should always be less lines of code, but lack of braces causes hesitation to add / remove lines due to extra step of adding/removing braces
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
  - arbitrary, but useful if you were to declare multiple pointers in one line (which you shouldn't do either...)
- No single line function definitions
  - They're hard to catch and differentiate w/ other code
- No single line enumerations
  - A bit more arbitrary than function definitions
  - Avoids need to go back and forth between single line and mutiple line format if changes were to be made
- Variable names
  - `uint32_t someVariableName = 0u`
  - **Camel case**
    - Lowercase for first word
    - Capitalize first letter of all other words
    - No space between words
- Typedefs
  - `typedef struct CircularBufferStruct CircularBuffer`
  - Camel case, but first letter is capitalized too
  - DON'T add `_t` suffix- that's reserved for code following POSIX like `size_t`
- Constants
  - `const char DEFAULT_MESSAGE[] = "Hello World\r\n"`
  - All uppercase
- Function names
  - `someFunctionName(uint32_t anArgument)`
  - Camel case
- Structs
  - Camel case, but first letter is capitalized too
- Java Docs
  - No Java Doc comment headers
  - We're not writing front facing API's, so we're not mandated to inject documentation in source code to generate nice Doxygen files
  - Less comments the better

## Can We Change Something?
- Everything is subject to change if we find anything painful, inefficient, etc
- We can ~~square up and duke it out~~ talk and make changes changes accordingly