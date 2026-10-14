*This project has been created as part of the 42 curriculum by pabbenit.*

# Libft

## Description

Libft is the first project of the 42 cursus. Its goal is to create a custom C library that reimplements a selection of functions from the standard C library (`libc`) and adds other useful functions for working with memory, strings, and linked lists.

The project allows working on and reinforcing fundamental C language concepts, including:

- Pointers.
- Pointer arithmetic.
- String manipulation.
- Existing memory manipulation (memmove, memset, memcpy, etc.).
- Manual memory management: when to allocate, use, and free memory.
	- Dynamic memory allocation using `malloc` and `calloc`.
	- Freeing memory using `free`.
	- Memory life cycle control and leak prevention.
- Structures.
- Function pointers.
- Linked lists.
- Use of file descriptors.
- Compiling multiple source files and generating object files.
- Use of Makefiles.
- Creation of static libraries.

The result of the project is a static library named:

```text
libft.a
```

This library can be used later in other C projects.

### Library Description

The library consists of several categories of functions.

#### Character Classification and Conversion Functions

These functions allow checking character properties (1 for true and 0 for false) or converting between uppercase and lowercase:

- `ft_isalpha`: checks if the received character is alphabetic.
- `ft_isdigit`: checks if the received character is a digit.
- `ft_isalnum`: checks if the received character is alphanumeric (alphabetic or digit).
- `ft_isascii`: checks if the received character is ASCII (ASCII numerical value range = [0-127]).
- `ft_isprint`: checks if the received character is printable ASCII (ASCII numerical value range [32-126]).
- `ft_toupper`: converts the received character (if alphabetic) to uppercase.
- `ft_tolower`: converts the received character (if alphabetic) to lowercase.

#### Memory Functions

These functions allow direct manipulation of memory blocks:

- `ft_memset`: fills the first `n` bytes of a memory area with the received value.
- `ft_bzero`: sets the first `n` bytes of a memory area to `0`.
- `ft_memcpy`: copies `n` bytes from a source memory area to a destination memory area. The behavior is undefined if the two areas overlap.
- `ft_memmove`: copies `n` bytes from a source memory area to a destination memory area, correctly handling any potential overlap between both areas.
- `ft_memchr`: searches for the first occurrence of a specific byte within the first `n` bytes of a memory area and returns a pointer to that position. Returns `NULL` if not found.
- `ft_memcmp`: compares the first `n` bytes of two memory areas byte by byte. Returns `0` if they are equal, a negative value if the first differing byte in the first area is smaller, and a positive value if it is greater.
- `ft_calloc`: dynamically allocates memory for `nmemb` elements of `size` bytes and initializes all allocated bytes to `0`.

These functions mainly work with generic pointers (`void *`) and allow writing, copying, moving, comparing, searching, and allocating memory.

#### String Functions

The library includes various functions designed to work with "true" C strings, meaning strings terminated with `'\0'`. These functions allow operations such as calculating lengths, copying strings, concatenating them, searching for characters or substrings, dynamically creating new strings, splitting strings, and applying functions to their characters.

- `ft_strlen`: calculates and returns the length of a string without counting the final null character `'\0'`.
- `ft_strlcpy`: copies a source string to a destination string, respecting the maximum available size and ensuring `'\0'` termination as long as the received size is greater than `0`. Returns the length of the source string.
- `ft_strlcat`: concatenates a source string to the end of a destination string, respecting the total available size. Returns the total length of the string it would have tried to create.
- `ft_strchr`: searches for the first occurrence of a character within a string and returns a pointer to that position. Returns `NULL` if not found.
- `ft_strrchr`: searches for the last occurrence of a character within a string and returns a pointer to that position. Returns `NULL` if not found.
- `ft_strncmp`: compares at most the first `n` characters of two strings. Returns `0` if they are equal, a negative value if the first one is smaller, and a positive value if it is greater.
- `ft_strnstr`: searches for the first occurrence of a substring `little` within a string `big`, examining at most `len` characters. Returns a pointer to the beginning of the match or `NULL` if not found.
- `ft_strdup`: allocates memory and creates a complete copy of the received string.
- `ft_substr`: allocates memory and creates a substring from a specific position in the original string with an indicated maximum length.
- `ft_strjoin`: allocates memory and creates a new string formed by the concatenation of two strings.
- `ft_strtrim`: allocates memory and creates a copy of a string, removing all characters included in the received set from the beginning and the end.
- `ft_split`: splits a string into multiple substrings using a character as a delimiter and returns a `NULL`-terminated array of strings.
- `ft_strmapi`: creates a new string by applying a function to each character of the original string, passing both the index and the character to the function.
- `ft_striteri`: iterates over a string and applies a function to each character, passing its index and the address of the character itself to allow its modification.

#### Conversion Functions

The library contains functions to perform conversions between numeric representations and strings:

- `ft_atoi`: converts a string to an integer.
- `ft_itoa`: performs the reverse operation, dynamically creating a string that represents an integer number.

#### File Descriptor Output Functions

Functions are also implemented to write information using a file descriptor:

- `ft_putchar_fd`: writes a character to the specified file descriptor.
- `ft_putstr_fd`: writes a string to the specified file descriptor.
- `ft_putendl_fd`: writes a string followed by a newline to the specified file descriptor.
- `ft_putnbr_fd`: writes the representation of an integer number to the specified file descriptor.


These functions allow writing characters, strings, and numbers to the specified descriptor.

#### Linked Lists

The last part of the library implements various operations to work with singly linked lists.

The structure used is:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Each node contains two elements:

- `content`: a generic pointer (`void *`) that allows storing the address of any data type.
- `next`: a pointer to the next node in the list. If the node is the last one, its value is `NULL`.

The functions implemented to manage linked lists are:

- `ft_lstnew`: allocates memory to create a new node, assigns the received content to `content`, and initializes `next` to `NULL`.
- `ft_lstadd_front`: adds a new node to the beginning of a list, making it the first node.
- `ft_lstsize`: iterates through a list and returns the total number of nodes it contains.
- `ft_lstlast`: iterates through a list and returns a pointer to its last node.
- `ft_lstadd_back`: adds a new node to the end of a list.
- `ft_lstdelone`: frees the content of a node using the received `del` function and subsequently frees the node itself, without freeing the following nodes.
- `ft_lstclear`: deletes and frees all nodes in a list and their contents using the `del` function. Upon completion, the pointer to the first node is set to `NULL`.
- `ft_lstiter`: iterates through all nodes in a list and applies a function to the content of each one.
- `ft_lstmap`: iterates through a list, applies a function to the content of each node, and creates a new list with the obtained results. If a memory allocation fails, it correctly frees the elements that had already been created.

These functions allow creating nodes, adding them to the beginning or end of a list, traversing the list, counting its elements, finding the last node, freeing nodes and contents, applying functions to the contents, and creating new transformed lists.

## Instructions

The project uses a `Makefile` to compile the source files and generate the static library.

To compile the library:

```bash
make
```

This command compiles the necessary `.c` files and generates:

```text
libft.a
```

The Makefile also has the following rules.

To remove object files:

```bash
make clean
```

To remove object files and the `libft.a` library:

```bash
make fclean
```

To remove all generated files and completely recompile the project:

```bash
make re
```

The files are compiled using the flags:

```text
-Wall -Wextra -Werror
```

To use Libft from another C program, the header file must be included:

```c
#include "libft.h"
```

Then, the program can be linked with the library during compilation.

For example:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o program
```

It can then be executed with:

```bash
./program
```

A simple usage example would be:

```c
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello, Libft!");
	if (!str)
		return (1);
	printf("%s\n", str);
	free(str);
	return (0);
}
```

To compile it along with Libft:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o program
```

## Resources

The main resources used during the development and learning of the project were:

- Official subject of the 42 Libft project.
- Unix/Linux manual pages using the `man` command.
- C language documentation.
- Standard C library documentation.
- Dynamic memory management documentation.
- References on pointers and pointer arithmetic.
- References on structures and linked lists.
- Makefiles documentation.
- `ar` documentation for creating static libraries.

Some manual pages that were especially useful during the project can be consulted using:

```bash
man malloc
man free
man strlen
man memset
man bzero
man memcpy
man memmove
man strchr
man strrchr
man strncmp
man memchr
man memcmp
man atoi
man calloc
```

Artificial intelligence has also been used as a support tool during the learning and development of the project.

AI has been mainly used to:

- Explain C language concepts.
- Review implementations made during development.
- Analyze edge cases.
- Understand errors and messages produced by the compiler.
- Prepare tests to verify the behavior of the functions.
- Understand the creation and use of a static library.

Artificial intelligence has been used as a tool for pedagogical support, review, and explanation. The project's functions have been worked on and understood individually with the goal of being able to explain their operation, implementation decisions, and behavior during the project defense.