#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "path_func.h"

#define MAX_LINE 1000

int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    char absolute_path[1000];
    char *words[100];
    while (1)
    {

        printf("myshell>\n");
        memset(line, 0, sizeof(line));
        if (fgets(line, MAX_LINE, stdin) == NULL)
        {
            printf("Fail to read the input stream");
            continue;
        }

        line[strcspn(line, "\n")] = '\0';

        printf("you entered: %s\n", line);

        if (!strcmp(line, "exit"))
        {
            break;
        }

        split(line, words, ' ');

        if (words[0] == NULL)
        {
            printf("No command specified\n");

            return 1;
        }
        if (!find_absolute_path(words[0], absolute_path))
        {
            printf("Command not found: %s\n", words[0]);

            return 1;
        }

        printf("absolute path = '%s'\n", absolute_path);
        execve(absolute_path, words, NULL);

        printf("execve failed");

        return 1;
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