#include "../all.h"

void	bombs_creation(t_map *map)
{
	int i;
	int rand;

	i = 0;
	rand = 0;
	while (i < map->mines)
	{
		rand = randint(map);
		if (map->cells[rand].hidden_val != '*')
		{
			map->cells[rand].hidden_val = '*';
			i++;
		}
	}
}
