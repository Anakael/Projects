#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
//Создание подобия map из STL
typedef struct
{
	char* key;
	char* value;
} Pair;
typedef struct
{
	Pair* table;
	int size;
} Map;

Map newMap();
void printMap(Map*);
void insertPair(Map*, char*, char*);
char* getValue(Map*, char*);
char* deleteValue(Map*, char*);
void freeMap(Map*);
#endif // !DICTIONARY_H