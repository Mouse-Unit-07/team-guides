# Team Rules

### Objective
- Build a cracked micromouse that zooms through a maze

## Do We Really Need All This Formality and New Tools?
- As a tiny team, probably not- we can get away w/ monoliths, sending each other files over chats, working without version control, etc if we wanted to

- ...But, provided we know that
  - managing piles of zip files on Discord is a pain
  - firmware will need to be re-written each time hardware changes (it takes forever)
  - asking each other about how something is implemented at the very last step when integrating together all project parts is a waste of time
  - debugging after writing code is a nightmare, especially when multiple engineers wrote something together
- ...There's no reason not to equip ourselves w/ modern know-how and tools that solve these issues

## Aight, So What're We Doing?
- We will introduce the bare minimum set of modern practices to:
  - Write working software as fast as possible
  - Write software that we can all quickly read and start tampering
  - Maximize parallel work and allow anyone to work on anything
  - Have no doubt in what we need to do
  - Implement everything on the Micromouse todo-list and feel like we have netherite weapons to take down a spider
- The minimum set of tools are:
  - **GitHub Organization**: Mouse Unit 07
    - all intel, documentation, and development in a single place
  - **GitHub Projects**: Mouse Unit 07 Kanban
    - streamlined division of labor and todo lists
  - **GitHub Discussions**: discussions repo
    - store useful conversations together w/ rest of development resources
  - **GitHub**: 
    - [development reference repos]
      - team-guides, engineering-sketches, reference documents, discussions, etc
    - [archive repos]
      - outdated works
    - [hardware repos]
      - schematic/layout pdfs, BOMs, design decision docs, etc
    - [software repos]
      - all relevant repos for anyone to work on anything
  - Software development streamlining and build automation tools
    - **Jenkins**, **JFrog Artifactory**, **Docker**, **Conan**, **CMake**, **CppUTest**, **CppCheck**, **gcov**, **Clang-format**

## Details Plz

### Read & Follow Key Books
- Let's follow principles introduced in the below books:
    - *Clean Code*
    - *Test-Driven Development for Embedded C*
    - *Modern C++ Programming with Test-Driven Development: Code Better, Sleep Better*
    - *The DevOps Handbook*
    - *UML Distilled*
- Below are things not specified in these books

### Development Practices
- No code reviews, but it's a free-for-all to write comments to nitpick
  - Comments must be resolved
- Don't directly push to main on Git repos
  - Again, no reviewing pull-requests, but isolates all development efforts and keeps main branch clean
- Commits
  - Check out **/team-guides/tool-guides/git-guide**
  - Use conventional commits
  - Don't stockpile a collection of commits for a single pull-request
- Repo names
  - all lowercase, dashes between words
- Filenames, directory names 
  - all lowercase
  - dashes between words if it's not for code
  - underscores between words if it's source files/folders
- Generate and share development items through GitHub Organization
  - No passing/storing stuff on Google Drive, Discord, etc
  - Store documentation you generate on GitHub Organization repo

### Programming
- 80 characters per line
  - Makes GitHub side-by-side view easy to see

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

- Variable names, typedefs
  - all lowercase, underscores between words

- Constants
  - all uppercase

- Function names
  - lowercase for first word
  - capitalize first letter of all other words
  - no space between words

- Structs
  - capitalize first letter of all words
  - no space between words

- Java Docs
  - We will eradicate all Java Doc comment headers- we're not writing front facing API's, so we're not mandated to inject documentation in source code to generate nice Doxygen files
  - Less comments the better

## Can We Change Something?
- Everything is subject to change if we find anything painful, inefficient, etc
- We can ~~square up and duke it out~~ talk and make changes changes accordingly