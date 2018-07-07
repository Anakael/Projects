#include "utils.h"
//Посимвольное считывание строки с консоли с ограниченным количеством символов
char* getString(size_t maxSize)
{
	size_t size=0;
	char* ret = (char*)malloc(sizeof(char)*(size+1));
	while ((ret[size]=getchar())!='\n')
	{
		ret = (char*)realloc(ret, sizeof(char) * (++size+1));
		if (size >= maxSize + 1)
			{
				size = 0;
				break;
			}
	}
	ret[size]=0;
	return ret;
}
//Длина строки
size_t myStringLength(char* str)
{
	size_t length = 0;
	while (*str++ != 0)
		length++;
	return length;
}
//Разбиение строки на подстроки
char** splitString(char* source,char separator)
{
	size_t length = 2;
	char** arrStr = (char**)malloc(sizeof(char*) * length);
	size_t size = 0;
	size_t offset = size;
	for (size_t i = 0; i < 2; i++)
	{
		arrStr[i] = (char*) malloc(sizeof(char) * (size+1));
		while (source[size] != separator && source[size] != '\n')
		{
			arrStr[i][size - offset] = source[size];
			arrStr[i] = (char*) realloc(arrStr[i],sizeof(char) * (++size+1));
		}
		if (arrStr[i][size - offset - 1] == ' ')
			arrStr[i] = (char*) realloc(arrStr[i],sizeof(char) * (--size));
		arrStr[i][size - offset] = 0;
		size += 4;
		offset = size;
	}
	return arrStr;
}
//Код ниже для небуфферизованного ввода символа
static struct termios old, new;
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}
/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}
