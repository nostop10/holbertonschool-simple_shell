# nostop shell

![image](https://github.com/nostop10/holbertonschool-simple_shell/assets/159030413/250e230b-93e3-481a-be32-76d1b2266363)

C- SIMPLE SHELL 🫥👨‍💻

📄 Ojective 

 to write a Simple Unix command interpreter

📝 DESCRIPTION

Simple Shell is a command line interpreter developed in C language that emulates the most basic features of "sh".
hsh is a simple shell program developed in C language that emulates the basic functionality of "sh" (Bourne Shell). It allows users to execute commands located in the PATH environment variable and provides support for some built-in commands. Please note that while hsh aims to provide essential shell functionality, some advanced features found in other shells may not be supported.

📓 MANUAL

I.TH HSH 1  "HSH 1 Manuel de la Simple Shell"

.SH NOM
hsh - holberton Simple Shell 

.SH SYNOPSIS
Run ./hsh [command] [argument] for interactive mode and echo "[command] [argument]" | ./hsh for non-interactive mode.

.SH DESCRIPTION
Simple Shell is a command line interpreter developed in C language that emulates the most basic features of "sh".
hsh is a simple shell program developed in C language that emulates the basic functionality of "sh" (Bourne Shell). It allows users to execute commands located in the PATH environment variable and provides support for some built-in commands. Please note that while hsh aims to provide essential shell functionality, some advanced features found in other shells may not be supported.

.SH COMPILATION
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

By using these compilation flags, the gcc command ensures that code is compiled in a strict manner, helping to identify and correct potential errors, as well as guaranteeing compliance with C language standards.


.SH MODES
The shell can be used in interactive or non-interactive mode. Interactive mode is the one in which the shell is typically used, the executable file is launched and we can enter commands. In non-interactive mode, you pass the command to the executable file with a pipe operator. In the "EXAMPLES" section, you can see how to use them.

.SH EXAMPLES
- Interactive Mode:
.TP
\r$ ./hsh
.TP
\r\rhsh$ ls -l
.TP
- Non-Interactive Mode:
.TP
\recho "ls -l" | ./hsh

.SH SUPPORTED COMMANDS
- ls: List directory contents
- cd: Change the shell working directory
- pwd: Print the current working directory
- cat: Concatenate and display files
- echo: Display a line of text
- mkdir: Make directories
- rmdir: Remove directories
- rm: Remove files or directories
- touch: Create an empty file or update file timestamps
- mv: Move or rename files or directories
- cp: Copy files or directories
- chmod: Change file modes or Access Control Lists
- chown: Change file owner and group
- grep: Print lines matching a pattern
- find: Search files and directories
- tar: Manipulate archive files
- gzip: Compress or decompress files
- top: Display Linux processes
- ps: Report a snapshot of the current processes
- kill: Send a signal to a process

INTEGRATED CONTROLS

       The following built-in commands are supported:

       env Displays current environment variables.

       exit Exits the command interpreter.

EXECUTING PROGRAMS IN THE PATH
In short, when hsh receives a command from the user, it first checks whether the command is an embedded command. If not, it searches for the command in the directories listed in the PATH environment variable, as well as by absolute or relative path. If it doesn't find the command, it displays an error message

.SH AUTHORS
# Evrade #

💿 PROTOTYPES

shell.c
void handle_input(char *buffer);
int execute_builtin(char **args, char *buffer);
void execute_external(char **args);


shell.h
 void process_input();

memory_manager.c
void free_tab(char **tab);
void clean(char *temp, char **args);

token.c
char **tokenizer(char *input, char *delimiter);
This prototype declares the tokenizer function, which takes two character pointers as input (a string and a delimiter) and returns a pointer to an array of character pointers (a list of strings).

execute.c 
int command_is_path(char *command);
char *check_paths(char *command, char **argv);
char *check_command(char *command, char **argv);

BuiltInCommand.c
int check_builtin(char *command, char **argv);
void exit_func(char **argv);
void printenv_func();

setpoint

Allowed editors: vim, emacs
All the files will be compiled on Ubuntu 20.04 LTS using gcc.
The code should use the betty style.
Global variables are not allowed.
No more than 5 functions per file.
The header files should be include guarded.
Your shell should not have any memory leaks.

✅ List of allowed functions and system calls

all functions from string.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

💾 Compilation command

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


