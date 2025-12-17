*This project has been created as part of the 42 curriculum by **pdiniz-l**.*

## ft_printf

### Description

The **ft_printf** project consists of implementing a simplified version of the standard C `printf` function.  
The goal is to reproduce its core behavior while respecting the constraints, coding standards, and low-level requirements of the **42 curriculum**.

This project focuses on understanding **variadic functions**, **format parsing**, **integer and string formatting**, and **output using the `write` system call**, while ensuring proper error handling and memory safety.

---

### Instructions

#### Compilation

The project is compiled using the provided `Makefile`.

Available targets:

```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and the library
make re     # recompile the project
```
This will generate the static library:
```bash
libftprintf.a
```
#### Usage

In `ft_printf.c` there is a comment with a main ready to test by using:
```bash
cc -Wall -Wextra -Werror ft_printf.c libftprintf.a
```
#### Supported Conversions

The ft_printf function supports the following format specifiers:

* `%c` — character

* `%s` — string

* `%d` / `%i` — signed decimal integer

* `%u` — unsigned decimal integer

* `%x` — hexadecimal (lowercase)

* `%X` — hexadecimal (uppercase)

* `%p` — pointer address

* `%%` — literal percent sign

##### Each helper function returns:

* The number of bytes written on success

* 1 in case of a write error

The main ft_printf function accumulates these values and returns the total number of bytes printed, matching the behavior of the standard printf.

#### Algorithm and Data Structure Choices
##### Format Parsing

The format string is processed character by character.

When a % is encountered, the following character is analyzed to determine the appropriate conversion.

A dispatcher function (chr_check) routes execution to the correct handler based on the specifier.

##### Variadic Arguments

The project uses va_list, va_start, va_arg, and va_end to retrieve arguments dynamically according to the detected format specifier.

##### Integer and Hexadecimal Conversion

Signed integers are printed using recursive or iterative digit extraction.

Unsigned values are used for `%u`, `%x`, `%X`, and `%p`.

For hexadecimal output, values are converted using base-16 logic.

Signed values are cast to unsigned types when required (e.g. long → unsigned long) to ensure correct representation.

#### Memory Management

* Dynamic memory allocation is used only when necessary (hexadecimal conversion).

* Every malloc call has a corresponding free.

* No memory leaks are introduced.

#### Error Propagation

Every helper function checks the return value of write.

In case of error, -1 is immediately propagated up to ft_printf.

This design ensures correctness, simplicity, and robustness while staying within project constraints.

#### File Structure

`ft_printf.c` - Main function that parses the format string, manages va_list, dispatches specifiers, and accumulates output size.

`chr_check.c` - Identifies the conversion specifier and calls the corresponding handler.

`digits.c` -  Computes the number of digits required for numerical conversions (used for hexadecimal output).

`ft_putchar.c` - Writes a single character using write.

`ft_putstr.c` - Writes a string, handling NULL values by printing (null).

`ft_putnbr.c` -  Prints signed integers.

`ft_put_unsigned_nbr.c` - Prints unsigned integers.

`ft_put_hex.c` - Converts and prints hexadecimal values using dynamic memory allocation.

`ft_put_void_pointer.c` - Prints pointer addresses in 0x... format.

`lower_or_upper.c` - Determines whether hexadecimal output should be lowercase or uppercase.

`ft_printf.h` - Header file containing prototypes and required includes.

`Makefile` - Compilation rules and standard targets.

### Resources

42 School — ft_printf subject

POSIX documentation:

* write(2)

* stdarg(3)

Manual pages:

* man printf

* man stdarg

* C standard library documentation
