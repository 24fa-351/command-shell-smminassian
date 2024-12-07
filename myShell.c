#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000
int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    while (1)
    {
        printf("myshell>");
        fgets(line, MAX_LINE, stdin);
        printf("you entered: %s", line);
        if (!strcmp(line, "exit\n"))
        {
            break;
        }
    }
    return 0;
}

// Create a command-line shell program like bash or Powershell. Have a prompt, example below.

// (done)Reads from input, writes to output. until "quit" or "exit".

// Implement "cd" and "pwd". (directly). cd must take a full or relative path.

// Implement the setting, deleting (unsetting) and getting of xsh environment vars:

// Read the PATH environment variable (from when the shell was started, not when/if it was set in xsh), and look for any command typed that is not directly implemented. Execute it when found; complain if not found.

// Implement "|" to separate commands and pipe output from one to the input of another.

// Implement "<" to pipe the contents of a file to the input of the command.

// Implement ">" to pipe the command output to a file.

// Implement "&" to run the command in the background. Otherwise, wait for the output.