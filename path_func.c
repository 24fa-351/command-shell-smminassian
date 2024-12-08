#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
void split(char *cmd, char *words[], char delimter);
bool find_absolute_path(char *cmd, char *absolute_path);
void add_character_to_path(char path[], char characterIADD);

void split(char *cmd, char *words[], char delimter)
{
    int word_count = 0;
    char *next_char = cmd;
    char current_word[1000];
    strcpy(current_word, "");

    while
}

bool find_absolute_path(char *cmd, char *absolute_path)
{
    char *directories[1000];

    split(getenv("PATH"), directories, ':');

    for (int ix = 0; directories[ix] != NULL; ix++)
    {
        char path[1000];
        strcpy(path, directories[ix]);
        add_character_to_path(path, '/');
        strcat(path, cmd);

        if (access(path, X_OK) == 0)
        {
            strcpy(absolute_path, path);
            return true;
        }
    }
    return false;
}

void add_character_to_path(char path[], char characterIADD)
{
    size_t len_of_path = strlen(path);
    path[len_of_path] = characterIADD;
}


int main(int argc, char *argv[])
{
    char absolute_path[1000];
    char *words[100];

    split(argv[2], words, ' ');

    if (words[0] == NULL)
    {
        printf("No command specified\n");
        return 1;
    }
    if(!find_absolute_path(words[0], absolute_path)){
        printf("Command not found: %s\n", words[0]);
        return 1;
    }

    for(int jx = 0; words[jx] != NULL; jx++){
        printf("words[%d] = '%s'\n", jx, words[jx]);
    }
    printf("absolute path = '%s'\n", absolute_path);
    execve(absolute_path, words, NULL);
    printf("execve failed");
    return 1;
}