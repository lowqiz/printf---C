## my_printf

## Description
**my_printf** is a personal project written in C that consists in reimplementing a simplified version of the standard `printf` function.

This project was developed as part of my early learning process in C programming and aims to better understand low-level concepts such as format parsing, output handling, and variadic functions.

This is **my first C project**, and it marks the beginning of my journey in software development.

---

## Features

The `my_printf` function supports a wide range of features inspired by the standard `printf` manual.

### Conversion Specifiers
- `%d` / `%i` : signed decimal integer
- `%u` : unsigned decimal integer
- `%o` : unsigned octal integer
- `%x` / `%X` : unsigned hexadecimal integer (lowercase / uppercase)
- `%b` : binary representation
- `%f` : decimal floating-point number
- `%e` / `%E` : scientific notation (lowercase / uppercase)
- `%g` / `%G` : shortest representation between `%f` and `%e` / `%E`
- `%c` : character
- `%s` : string
- `%p` : pointer address
- `%n` : number of characters written so far
- `%%` : prints a percent character

### Length Modifiers
- `hh` : signed or unsigned char
- `h`  : short int
- `l`  : long int
- `ll` : long long int
- `q`  : quad type (implementation-dependent)

### Flags and Formatting Options
- `0` : zero-padding
- `+` : forces the sign (`+` or `-`) to be displayed for numeric values
- `*` : dynamic width or precision passed as an argument

### Notes
This implementation is intended for educational purposes.  
Some behaviors may be simplified or partially implemented compared to the standard `printf`.

---

## Technical Details
- Language: **C**
- Uses variadic arguments (`stdarg.h`)
- Manual parsing of the format string
- Output written to standard output

---

## Purpose of the Project
The main goals of this project were to:
- Understand how `printf` works internally
- Practice string parsing and conditional logic
- Learn how to handle variadic arguments in C
- Improve code structure and readability

---

## Learning Progress
As this is my **first project**, it may contain simple implementations or limitations.  
However, this repository reflects my starting point,and my **progress and improvements can be seen through my other repositories** over time.

---

## Author
Loris Pellizzari  
Computer Science student (1st year)
