#ifndef UTILS_H
#define UTILS_H

#include <termios.h>
#include <stdlib.h>
#include <stdio.h>

char* getString(size_t);
char** splitString(char*,char);
char getch(void) ;
size_t myStringLength(char*);

#endif // !UTILS_H