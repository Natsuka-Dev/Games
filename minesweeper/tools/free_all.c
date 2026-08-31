#include <stdlib.h>

#include "../all.h"

void	free_all(t_map *map)
{
	for (int i = 0; i < (map->x * map->y); i++)
		free(map->cells[i].val);
	free (map->cells);
	free (map);
}
