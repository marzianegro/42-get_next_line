# *get_next_line*

## Description
This project consists of a function that reads a line from a file descriptor. The primary objective is to implement a function that can handle reading and managing multiple file descriptors without losing the reading thread.

## Features
- **Line Reading**: Retrieves a line from a file descriptor.
- **Dynamic Memory Management**: Utilizes dynamic memory allocation to handle lines of varying lengths.
- **Multiple File Descriptor Support**: Can manage and read from multiple file descriptors simultaneously.
- **Handles Buffering**: Efficiently buffers input to minimize read operations.

## Getting Started
### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/marzianegro/42-get_next_line.git
    ```

2. Navigate to the project directory:

    ```bash
    cd 42-get_next_line
    ```

3. Compile the project:

    ```bash
    make
    ```

### Usage
1. Include the `get_next_line.h` header file in your project:

    ```c
    #include "get_next_line.h"
    ```

2. Call the `get_next_line` function to read a line from a file descriptor:

    ```c
    char *line;
    int fd;

    while (get_next_line(fd, &line) > 0)
    {
        // Process the line as needed
        printf("%s\n", line);
        // Free the allocated memory for the line
        free(line);
    }
    ```

### Example
```c
#include "get_next_line.h"

int main()
{
    int		fd;
    char	*line;

    fd = open("example.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
