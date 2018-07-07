#include "dictionary.h"
#include "utils.h"

int main(int argc, char* argv[])
{
	//Инициалзиация и заполнение из файла, если передан
	Map map = newMap();
	if (argc > 1)
	{
		FILE* input = fopen(argv[1], "r");
		if(input)
		{
			size_t countUnReadable = 0;//Строки, которые нельзя прочитать просто игнорируем и оповещаем об их количестве
			char buffer[300];
			while(fgets(buffer, 300, input))
			{
				char** arrStr = splitString(buffer,'=');
				if (myStringLength(arrStr[0]) <= 128 && myStringLength(arrStr[1]) <= 128)
					insertPair(&map,arrStr[0], arrStr[1]);
				else
					countUnReadable++;
			}
			fclose(input);
			if(countUnReadable)
			printf("Unreadable pair: %zd\n",countUnReadable);
		}
		else
		{
			perror(argv[0]);
			return -1;
		}
			
	}
	//Создание консольного интерфейса
	char codeMenu;
	do
	{
		printf("What do you want to do?\n");
		printf("(P)rint dictionary\n");
		printf("(I)nsert interpretation\n");
		printf("(F)ind interpretation\n");
		printf("(D)elete interpretation\n");
		printf("(E)xit\n");
		codeMenu = getch();
		switch (codeMenu)
		{
			//Печать
			case 'p':
				printMap(&map);
				break;
			case 'i':
			//Добавление с проверками. str1 и str2 не очищаем, так как области памяти, занимаемые ими используются и очищаются в дальнейшем
				printf("Enter word\n");
				char* str1 = getString(128);
				if(!str1)
				{
					printf("Overflow");
					break;
				}
				printf("Enter interpretation\n");
				char* str2 = getString(128);
				if(!str2)
				{
					printf("Overflow");
					break;
				}
				insertPair(&map, str1, str2);
				printf("Interpretation added successfuly\n");
				break;
			//Поиск
			case 'f':
				printf("Enter word\n");
				str1 = getString(128);
				if(!str1)
				{
					printf("Overflow");
					break;
				}
				printf("%s => %s\n",str1,getValue(&map,str1));
				free(str1);
				break;
			//Удаление
			case 'd':
				printf("Enter word\n");
				str1 = getString(128);
				if(!str1)
				{
					printf("Overflow");
					break;
				}
				printf("%s => %s\n",str1,deleteValue(&map,str1));
				free(str1);
				break;
			//Интерактивный выход из приложения
			case 'e':
				printf("Do you want save dictionary?[Y/n]\n");
				char codeSave;
				codeSave = getch();
				if (codeSave != 'n')
				{
					//По умолчанию будет перезаписывать открытый файл
					if (argc > 1)
						printf("Enter path (Press enter for saving into %s)\n",argv[1]);
					else
						printf("Enter path");
					char* path = getString(150);
					FILE* output;
					//ОТкрытие файла и запись
					if (*path == *(char*)"" && argc > 1)
						output = fopen(argv[1],"w");
					else
						output = fopen(path,"w");
					if (output)
					{
						for (size_t i = 0; i < map.size; i++)
							fprintf(output,"%s => %s\n",map.table[i].key, map.table[i].value);
						fclose(output);
						printf("Dictionary save successfuly\n");
					}
					//Не завершаем аварийно работу приложения, чтобы не потерять данные
					else
					{
						printf("Error while writing a file\n");
						codeMenu = 'p';	
					}
					free(path);
				}
				break;
			default:
				printf("Invalid input\n");
				break;
		}
	}while (codeMenu != 'e');
	freeMap(&map);//Освобождение памяти структуры
	return 0;
}
