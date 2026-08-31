#include <ncurses.h>
#include <locale.h>

#include "../all.h"

#define WHITE_BLACK 0
#define BLACK_WHITE 1
#define BLUE_BLACK 2
#define BLUE_WHITE 3
#define GREEN_BLACK 4
#define GREEN_WHITE 5
#define RED_BLACK 6
#define RED_WHITE 7
#define WHITE_RED 18

void	map_display(t_map *map, int pos)
{
	t_elem	*node;

	setlocale(LC_ALL, "");
	addwstr(L"┌");
	for(int i = 0; i < map->x; i++)
		addwstr(L"──");
	addwstr(L"─┐\n│ ");
	for (int i = 0; i < ((map->x) * (map->y)); i++)
	{
		node = &map->cells[i];
		if (i && !(i % (map->x)))
			addwstr(L"│\n│ ");
		if (i == pos)
			color_cell(node->val, BLACK_WHITE); // node->val &node->hidden_val
		else
			color_cell(node->val, WHITE_BLACK); // node->val &node->hidden_val
		printw(" ");
	}
	addwstr(L"│\n└");
	for (int i = 0; i < map->x; i++)
		addwstr(L"──");
	addwstr(L"─┘\n");
}

void	hidden_map_display(t_map *map, int pos)
{
	t_elem	*node;

	setlocale(LC_ALL, "");
	addwstr(L"┌");
	for(int i = 0; i < map->x; i++)
		addwstr(L"──");
	addwstr(L"─┐\n│ ");
	for (int i = 0; i < ((map->x) * (map->y)); i++)
	{
		node = &map->cells[i];
		if (node->hidden_val == '0')
			map->cells[i].hidden_val = ' ';
		if (i && !(i % (map->x)))
			addwstr(L"│\n│ ");
		if (i == pos)
			color_cell(&node->hidden_val, WHITE_RED);
		else
			color_cell(&node->hidden_val, WHITE_BLACK);
		printw(" ");
	}
	addwstr(L"│\n└");
	for (int i = 0; i < map->x; i++)
		addwstr(L"──");
	addwstr(L"─┘\n");
}
