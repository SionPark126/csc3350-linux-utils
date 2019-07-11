# Lab 1 - Linux Utilities
In this lab, you will implement your own "cool" versions of some popular Linux programs. All programs must
be written in C. **No C++ or other languages are allowed.** All programs must be built and tested on
`luke.cs.spu.edu` – your code must work on `luke`, I will not test it elsewhere.

You will be working **individually** for this lab. You may discuss high-level concepts with other students,
but you should never share solutions or show each other code.

There are three requirements for this assignment that contribute to your final grade: the programs
themselves, comments and style, and GitHub commits.

### The Programs
  Note: parameters in `[]` are optional, parameters in `<>` are required. The `|` (pipe) means "or."
  
#### cool_cat (20 points)
  -Usage: `./cool_cat [file.txt]`
  
  -If the `[file.txt]` argument is passed, open the file and print it to `stdout`. If there is no second argument, repeat what the user types on `stdin` back to `stdout` (until the user hits CTRL+D to indicate EOF).

  -Make sure to compare your output to `cat`. Note this is not exactly like `cat`: only *one* file argument should be accepted, and we are not implementing the various command line flags.
  
  -Make sure to fail gracefully if the file does not exist or if > 2 arguments are passed. 
    
#### cool_echo (20 points)
  -Usage: `./cool_echo [arg] [arg] … [arg]`
  
  -Print all `[arg]` arguments to `stdout`.
  
  -If there are no `[arg]` arguments, simply print a newline and end the program.
  
  -Make sure to compare your output to `echo`. Note this is not exactly like `echo`, since we are not implementing the various command line flags.
  
  -Make sure to fail gracefully as needed (no specific requirements).

#### cool_head (20 points)
  -Usage: `./cool_head [-n N] [file.txt]`
  
  -If `[file.txt]` is specified, print the first N lines of that file (default is 5 lines if `-n` is not used). Otherwise, read from `stdin` until the user hits CTRL+D, and print the first N lines typed by the user.
  
  -If the `[-n N]` flag is used, print the first N lines.
  
  -The `[file.txt]` and `[-n N]` order should not matter – both orderings should be allowed.
  
  -Make sure to compare your output to `head`. Note this is not exactly like `head`: only one file argument should be accepted, and we are not implementing the various command line flags (except for `-n`). In addition, `head` by default prints the first 10 lines, `cool_head` prints 5.
  
  -Make sure to fail gracefully, including but not limited to: if the file does not exist, if too many (or too few) arguments are passed, or if the argument order is wrong (e.g., `./cool_head -n file.txt 10`).

#### cool_wc (30 points)
  -Usage: `./cool_wc [-l|c] [file.txt]`
  
  -If `[file.txt]` is specified, print a count of the number of words in `file.txt`.
  
  -If no `[file.txt]` argument is specified, read from `stdin` until the user hits CTRL+D.
  
  -If the `-l` (lowercase L) flag is specified, print the number of lines only.
  
  -If the `-c` flag is specified, print the number of characters only.
  
  -If neither `-l` nor `-c` are specified, print the count of words.
  
  -For simplicity, only let the user enter one of `-l` or `-c` (not both).
  
  -The `[file.txt]` and `[-l|c]` flag order should not matter -- all orderings should be accepted.
  
  -Note this is not exactly like `wc`: only one file argument should be accepted, and we are not implementing the various command line flags (except for `-l` and `-c`).
  
  -Make sure to fail gracefully, including but not limited to: if the file does not exist, or if too many (or too few) arguments are passed.

#### Makefile (10 points)
  Add a single file, called `Makefile`, with targets to build each of the programs. In addition, `make all` should make all four programs, and `make clean` should remove the executables.  Invoking `make` should automatically invoke the `all` target.

#### Tips:
  -Do not reinvent the wheel!  For example, use `getopt` to process command line arguments in C.  For "common" tasks like this, do some research to see what your options are.  If you find that you need a non-standard library, then it is probably something you have to implement yourself - if unsure, ask!
  
  -Use `fopen`, `fclose`, etc. instead of `open`, etc. See `man getline` for a good example of how to use these. Make sure to use `fclose` to close your streams (especially the file streams!).
  
  -If you run into segmentation faults (segfaults) and don't see output you expected to precede the crash, add `fflush(<buffer>)` (e.g., `fflush(stdout)`) after relevant output statements to ensure the buffer is flushed.

  -You may assume lines are 256 characters (bytes) or less.

  -Your programs should fail *gracefully* for bad inputs. *Gracefully* means you should print nice error messages to `stderr` when appropriate. *At a minimum* you should handle the cases mentioned above, but you should think carefully about other common failure cases and account for those. 
  
  -You may not use **any** command line programs already installed, i.e., you may not use `exec` or any variants to call `/bin/cat`, `/bin/wc`, etc.

  -Remember that spacing matters on the command line. For example, `head -n10 file.txt` works, whereas `wc - c file.txt` fails. For simplicity, you may reject any inputs that do not match the specifications listed above (e.g., it is OK if `./cool_head -n10 file.txt` fails gracefully).
  
  -You should not reference any code online or solicit help for how to implement these utilities. Only look at references for the C functions. When in doubt, use the `man` pages and ask Dr. Dingler.
  
### Comments and Code Style

#### Style and other requirements:
  -All lines should be < 80 characters wide for readability in a terminal program (80 is the standard width).
  
  -Always check the return types for any functions you use. Always make informed decisions about what arguments you pass to functions, especially syscalls. See #2 below for rules on comments.
  
  -Pick a coding style and stick with it. Good, consistent variable names, identifier style, curly brace usage, tabs, etc. are all important. No specific style will be enforced, but you should follow best practices (generally avoid single-letter variable names and global variables unless necessary, etc.).
  
#### Comment Requirements:
  -Your code should include a significant number of comments.
  
  -All function calls should be well-commented, with explanations for what the parameters and arguments mean, what the function returns, and why you dealt with the return value the way you did. Here is an example of good comments for calling `fopen`:
  
    `//This call to fopen takes the path to a file to open
    
    // (the argument is argv[1], the filename provided by
    
    // the user), followed by the access mode (the “r” argument
    
    // means read only). fopen returns a FILE * (pointer to
    
    // a stream representing the open file), or NULL if the
    
    // operation failed, in which case the program ends.`

  This clearly shows that you have thought about each of the parameters and passed appropriate arguments, and understand what the function is returning.
  
  Here is an example of bad comments for `fopen`:
  
    `//fopen takes a path and a mode and opens a file`
    
  This is too generic, and doesn’t explain what you are doing or show that you understand what you have done.

  -Comment style is up to you, but make it look somewhat neat.
  
  -Include a short `USAGE` file that explains how to use each of the programs (i.e., include the a “usage:… “ for each file), and a short overview of what they do.

  **Remember, your comments are how you demonstrate to me you know what your program does, and that it is your own work.**
  
### GitHub and Commit Messages
I am looking for three things:

  -Frequent commits: you should be making commits often. This means after writing any significant (working) code. I would expect anywhere from 5-10 commits per program -- less for shorter programs like `cool_cat` and more for something like `cool_head`, but no strict count is required. You should try to avoid committing broken code – when working in teams, this is generally frowned upon -- but I will not check for that (since you are working individually).
  
  -Good commit messages: commit messages should be concise, clear, and well-formatted. You should clearly explain what the changes are, why you made them, and any TODOs leftover from what you did. If something you commit is broken (or if you broke something), that should be clear as well. This site has good guidelines for commit messages: https://chris.beams.io/posts/git-commit/ (warning: spoilers for original Tron film!).
  
  -A reasonably Git workflow: at a minimum, you need to follow the add/commit/push workflow.  **All must be completed on luke for this assignment.  If you have a personal Linux installation you would like to use, you must see me in person to get approval**.  Uploading to GitHub through the Web interface or any other means is **not allowed**.
  
### What to turn in: your code for each program, your `Makefile` and your `USAGE` file, all submitted via GitHub Classroom.  I will grade the last GitHub commit before the submission deadline.

### Note on grading: the assignment is out of 100 points but there are no points explicitly set aside for anything but the four programs.  The requirements under "Comments and Code Style" and "GitHub and Commit Messages" are expectations you will adhere to when writing your code, similar to the requirements you might have as a software developer on a team in industry.  Failure to adhere to these will result in -10% for each occurrence.  That means, -10% for poorly-commented code, -10% for improper use of git/GitHub (e.g., bad workflow, bad commit messages), etc.  
