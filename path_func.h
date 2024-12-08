#ifndef PATH_FUNC_H
#define PATH_FUNC_H

#include <stdbool.h>

void split(char *cmd, char *words[], char delimter);
bool find_absolute_path(char *cmd, char *absolute_path);
void add_character_to_string(char path[], char characterIADD);

#endif