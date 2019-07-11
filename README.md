# Lab 1 - Linux Utilities

This project is implementing own linux programs.

### The Project Description

  Note: parameters in `[]` are optional, parameters in `<>` are required. The `|` (pipe) means "or."
  
#### cool_cat
  -Usage: `./cool_cat [file.txt]`
  
  -If the `[file.txt]` argument is passed, open the file and print it to `stdout`. If there is no second argument, repeat what the user types on `stdin` back to `stdout` (until the user hits CTRL+D to indicate EOF).

  -Make sure to compare your output to `cat`. Note this is not exactly like `cat`: only *one* file argument should be accepted, and we are not implementing the various command line flags.
  
  -Make sure to fail gracefully if the file does not exist or if > 2 arguments are passed. 
    
#### cool_echo
  -Usage: `./cool_echo [arg] [arg] … [arg]`
  
  -Print all `[arg]` arguments to `stdout`.
  
  -If there are no `[arg]` arguments, simply print a newline and end the program.
  
  -Make sure to compare your output to `echo`. Note this is not exactly like `echo`, since we are not implementing the various command line flags.
  
  -Make sure to fail gracefully as needed (no specific requirements).

#### cool_head
  -Usage: `./cool_head [-n N] [file.txt]`
  
  -If `[file.txt]` is specified, print the first N lines of that file (default is 5 lines if `-n` is not used). Otherwise, read from `stdin` until the user hits CTRL+D, and print the first N lines typed by the user.
  
  -If the `[-n N]` flag is used, print the first N lines.
  
  -The `[file.txt]` and `[-n N]` order should not matter – both orderings should be allowed.
  
  -Make sure to compare your output to `head`. Note this is not exactly like `head`: only one file argument should be accepted, and we are not implementing the various command line flags (except for `-n`). In addition, `head` by default prints the first 10 lines, `cool_head` prints 5.
  
  -Make sure to fail gracefully, including but not limited to: if the file does not exist, if too many (or too few) arguments are passed, or if the argument order is wrong (e.g., `./cool_head -n file.txt 10`).

#### cool_wc
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

#### Makefile
  Add a single file, called `Makefile`, with targets to build each of the programs. In addition, `make all` should make all four programs, and `make clean` should remove the executables.  Invoking `make` should automatically invoke the `all` target.


