#include "../all.h"

void	digits_creation(t_map *map)
{
	for (int i = 0; i < (map->x * map->y); i++)
	{
		if (map->cells[i].hidden_val == '*')
		{
			if (i - map->x >= 0 && (map->cells[i - map->x].hidden_val) != '*') // top
				map->cells[i - map->x].hidden_val++;
			if (i + map->x < (map->x * map->y) && (map->cells[i + map->x].hidden_val) != '*') // bottom
				map->cells[i + map->x].hidden_val++;
			if (i % map->x && (map->cells[i - 1].hidden_val) != '*') // left
				map->cells[i - 1].hidden_val++;
			if ((i + 1) % map->x && (map->cells[i + 1].hidden_val) != '*') // right
				map->cells[i + 1].hidden_val++;
			if (i - (map->x + 1) >= 0 && (i % map->x) && (map->cells[i - (map->x + 1)].hidden_val) != '*') // top left
				map->cells[i - (map->x + 1)].hidden_val++;
			if (i - (map->x - 1) >= 0 && ((i + 1) % map->x) && (map->cells[i - (map->x - 1)].hidden_val) != '*') // top right
				map->cells[i - (map->x - 1)].hidden_val++;
			if (i + (map->x + 1) < (map->x * map->y) && ((i + 1) % map->x) && (map->cells[i + (map->x + 1)].hidden_val) != '*') // bottom left
				map->cells[i + (map->x + 1)].hidden_val++;
			if (i + (map->x - 1) < (map->x * map->y) && (i % map->x) && (map->cells[i + (map->x - 1)].hidden_val) != '*') // bottom right
				map->cells[i + (map->x - 1)].hidden_val++;
		}
	}
}