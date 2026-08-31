#include <ncurses.h>

#include "../all.h"

int	map_cursor(t_map *map, int *pos, char letter)
{
	clear();
	if (letter == 'A' && *pos >= map->x) // going up
		(*pos) -= map->x;
	else if (letter == 'B' && *pos < (map->x * map->y) - map->x) // going down
		(*pos) += map->x;
	else if (letter == 'C' && *pos < ((map->x) * map->y) && ((*pos) + 1) % (map->x)) // going right
		(*pos)++;
	else if (letter == 'D' && *pos > 0 && *pos % (map->x)) // going left
		(*pos)--;
	else if (letter == 32 && map->cells[*pos].val[0] != '*') // click
	{
		if (map->cells[*pos].hidden_val == '*')
			return (1);
		else if (map->cells[*pos].hidden_val == '0')
			map_partial_display(map, *pos);
		else
			map->cells[*pos].val[0] = map->cells[*pos].hidden_val;
	}
	else if (letter == 'f' && (map->cells[*pos].val[0] == '.' || map->cells[*pos].val[0] == '*')) // adding or removing a flag
		map->cells[*pos].val[0] = (map->cells[*pos].val[0] == '.') ? '*' : '.';
	return (0);
}
