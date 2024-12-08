#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>

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
        }
        if (!strcmp(words[0], "cd"))
        {
            if (!find_absolute_path(words[1], absolute_path))
            {
                printf("path not found: %s\n", words[1]);
            }
            else if (find_absolute_path(words[1], absolute_path))
            {
                printf("original directory is %s\n", getcwd(absolute_path, sizeof(absolute_path)));
                chdir(words[1]);
                printf("new directory is %s\n", getcwd(absolute_path, sizeof(absolute_path)));
            }
        }
        if (!strcmp(words[0], "pwd"))
        {
            printf("your directory is %s\n", getcwd(absolute_path, sizeof(absolute_path)));
        }
        if (!strcmp(words[0], "ls"))
        {
            struct dirent *de;

            DIR *dr = opendir(".");

            if (dr == NULL)
            {
                printf("Could not oepn current directory");
            }
            while ((de = readdir(dr)) != NULL)
            {
                printf("%s\n", de->d_name);
            }
            closedir(dr);
        }
    }

    return 0;
}

// Create a command-line shell program like bash or Powershell. Have a prompt, example below.

// (done)Reads from input, writes to output. until "quit" or "exit".

// (done)Implement "cd" and "pwd". (directly). cd must take a full or relative path.

// Implement the setting, deleting (unsetting) and getting of xsh environment vars:

// Read the PATH environment variable (from when the shell was started, not when/if it was set in xsh), and look for any command typed that is not directly implemented. Execute it when found; complain if not found.

// Implement "|" to separate commands and pipe output from one to the input of another.

// Implement "<" to pipe the contents of a file to the input of the command.

// Implement ">" to pipe the command output to a file.

// Implement "&" to run the command in the background. Otherwise, wait for the output.