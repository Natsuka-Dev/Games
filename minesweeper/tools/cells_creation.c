#include <stdlib.h>

#include "../all.h"

void	cells_creation(t_map *map)
{
	map->cells = malloc((map->x * map->y) * sizeof(t_elem));
	if (!map->cells)
	{
		free(map);
		return;
	}
	for (int i = 0; i < (map->x * map->y); i++)
	{
		map->cells[i].val = '.';
		map->cells[i].hidden_val = '0';
		map->cells[i].pos = i;
	}
}
