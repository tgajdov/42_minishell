# System Functions Documentation

## Command Line and History Functions:
[The GNU Readline Library](https://www.gnu.org/software/readline/)
- **readline**:
    - Reads a line from standard input with line editing and auto-completion.
    - Commonly used in command interpreters.

- **add_history**:
    - Adds a command to the command history.

- **rl_clear_history**:
    - Clears the saved command history.

NB: the following functions are useful for handling signals and subshells
- **rl_on_new_line**:
    - Informs the system that the user is on a new line.

- **rl_replace_line**:
    - Replaces the current line with a new line.

- **rl_redisplay**:
    - Redisplays the current line.


## Memory Management Functions:

- **printf**:
    - Prints formatted data to standard output.

- **malloc**:
    - Allocates dynamic memory.

- **free**:
    - Frees memory previously allocated by malloc.

## Basic I/O Functions:

- **write**:
    - Writes data to a file or file descriptor.

- **access**:
    - Checks the existence and permissions of a file.

- **open**:
    - Opens a file and returns a file descriptor.

- **read**:
    - Reads data from a file or file descriptor.

- **close**:
    - Closes a file descriptor.

## Process Management Functions:

- **fork**:
    - Creates a new process by duplicating the calling process.

- **wait**:
    - Waits for a child process to terminate.

- **waitpid**:
    - Waits for a specific child process to terminate.

- **wait3**:
    - Waits for a child process to terminate and provides resource usage information.

- **wait4**:
    - Waits for a specific child process to terminate and provides resource usage information.

## Signal Management Functions:

- **signal**:
    - Sets a handler for a signal.

- **sigaction**:
    - Changes the action taken by a process on receipt of a signal.

- **sigemptyset**:
    - Initializes a signal set to empty.

- **sigaddset**:
    - Adds a signal to a signal set.

- **kill**:
    - Sends a signal to a process or group of processes.

## Process Termination Functions:

- **exit**:
    - Terminates the current process with a given status.

## Directory and File Management Functions:

- **getcwd**:
    - Gets the current working directory.

- **chdir**:
    - Changes the current working directory.

- **stat**:
    - Retrieves information about a file.

- **lstat**:
    - Like stat, but does not follow symbolic links.

- **fstat**:
    - Retrieves information about an open file.

- **unlink**:
    - Deletes a file.

- **execve**:
    - Replaces the current process image with a new program.

## File Descriptor Management Functions:

- **dup**:
    - Duplicates a file descriptor.

- **dup2**:
    - Duplicates a file descriptor to a given descriptor.

- **pipe**:
    - Creates a pipe for inter-process communication.

## Directory Management Functions:

- **opendir**:
    - Opens a directory for reading.

- **readdir**:
    - Reads an entry from an open directory.

- **closedir**:
    - Closes an open directory.

## Error Display Functions:

- **strerror**:
    - Returns a string describing an error.

- **perror**:
    - Prints an error message to standard error.

## Terminal Management Functions:

- **isatty**:
    - Checks if a file descriptor is associated with a terminal.

- **ttyname**:
    - Returns the name of the terminal associated with a file descriptor.

- **ttyslot**:
    - Returns the slot number of the terminal for the current terminal.

- **ioctl**:
    - Controls device parameters (often used for terminals).

## Environment Variable Functions:

- **getenv**:
    - Gets the value of an environment variable.

## Terminal Attribute Functions:

- **tcsetattr**:
    - Sets terminal attributes.

- **tcgetattr**:
    - Gets terminal attributes.

## Terminal Capability (termcap) Functions:

- **tgetent**:
    - Loads the terminal capabilities database.

- **tgetflag**:
    - Gets the value of a terminal capability flag.

- **tgetnum**:
    - Gets the numeric value of a terminal capability.

- **tgetstr**:
    - Gets a string value of a terminal capability.

- **tgoto**:
    - Generates a cursor movement control sequence.

- **tputs**:
    - Outputs a terminal control string with delays.

These functions cover a wide range of system operations commonly used in C programming under Unix/Linux.
