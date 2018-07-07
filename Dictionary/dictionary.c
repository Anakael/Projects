#include "dictionary.h"
//Конструктор структуры
Map newMap()
{
	Map map;
	map.size = 0;
    return map;
}
//Добавление пары ключ-значение
void insertPair(Map* map, char* key, char* value )
{
	if (!map->size)
		map->table = (Pair*)malloc(sizeof(Pair));
	else
		map->table = (Pair*)realloc(map->table,sizeof(Pair) * (map->size + 1));
	map->table[map->size].key = key;
	map->table[map->size].value = value;
	map->size++;
}
//Вывод всех пар ключ-значение
void printMap(Map* map)
{
	for (size_t i = 0; i < map->size; i++)
	{
		printf("%s => %s\n",map->table[i].key,map->table[i].value);			
	}
}
//Получание значение по ключу(Возможно есть потенциал для оптимизации поиска по отсортированной коллекции)
char* getValue(Map* map, char* str)
{
	char* value = "No match found";
	for (size_t i = 0; i < map->size; i++)
	{
		if (*map->table[i].key == *str)
			value = map->table[i].value;
	}
	return value;
}
//Удаление значения по ключу с выводом результата работы
char* deleteValue(Map* map, char* str)
{
	for (size_t i = 0; i < map->size; i++)
	{
		if (*map->table[i].key == *str)
		{
			for (size_t j = i; j < map->size - 1; j++)
			{
				map->table[j].key = map->table[j+1].key;
				map->table[j].value = map->table[j+1].value;
			}
			map->table = (Pair*)realloc(map->table, sizeof(Pair) * (--map->size));
			return "Deleted successfuly";
		}
	}
	return "No match found";
}
//Безопасное свобождение коллекции
void freeMap(Map* map)
{
	for (size_t i = 0; i < map->size; i++)
	{
		free(map->table);
		map->table = 0;
	}
}