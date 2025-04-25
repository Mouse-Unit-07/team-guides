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
- TLDR notes provided in [team-guides/essential-references/tldr-notes](https://github.com/Mouse-Unit-07/team-guides/tree/main/essential-references/tldr-notes)
- Below are things not specified in these books

### Development Practices
- No code reviews, but it's a free-for-all to write comments to nitpick
  - Comments must be resolved
- Don't directly push to main on Git repos
  - Again, no reviewing pull-requests, but isolates all development efforts and keeps main branch clean
- Branches should have short lives
  - As soon as a development branch is done, delete it
- Commits
  - Check out [team-guides/tool-guides/git-guide](https://github.com/Mouse-Unit-07/team-guides/blob/main/tool-guides/git-guide/git_guide.md)
  - Use conventional commits
  - Don't stockpile a collection of commits for a single pull-request
- Repo names
  - All lowercase, dashes between words
- Filenames, directory names 
  - All lowercase
  - Dashes between words if it's not for code
  - Underscores between words if it's source files/folders
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
  - All lowercase, underscores between words

- Constants
  - All uppercase

- Function names
  - Lowercase for first word
  - Capitalize first letter of all other words
  - No space between words

- Structs
  - Capitalize first letter of all words
  - No space between words

- Java Docs
  - We will eradicate all Java Doc comment headers- we're not writing front facing API's, so we're not mandated to inject documentation in source code to generate nice Doxygen files
  - Less comments the better

## Can We Change Something?
- Everything is subject to change if we find anything painful, inefficient, etc
- We can ~~square up and duke it out~~ talk and make changes changes accordingly