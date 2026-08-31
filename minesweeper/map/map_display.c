#include <ncurses.h>
#include <locale.h>

#include "../all.h"

#define WHITE_BLACK 0
#define BLACK_WHITE 1
#define RED_MY_FONT 6
#define WHITE_RED 18

void	map_display(t_map *map, int pos, int done)
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
		{
			if (done)
				color_cell(&node->hidden_val, WHITE_RED);
			else
				color_cell(node->val, BLACK_WHITE);
		}
		else if (done && map->cells[i].hidden_val == '*')
			color_cell(&node->hidden_val, WHITE_BLACK);
		else if (done && map->cells[i].val[0] == '*')
			color_cell("*", RED_MY_FONT);
		else
			color_cell(node->val, WHITE_BLACK);
		printw(" ");
	}
	addwstr(L"│\n└");
	for (int i = 0; i < map->x; i++)
		addwstr(L"──");
	addwstr(L"─┘\n");
}
