#include <stdlib.h>

#include "../all.h"

void free_all(t_map *map)
{
	free(map->cells);
	free(map);
}
