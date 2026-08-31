#include "../all.h"

static void	map_angles_disp(t_map *map, int pos)
{
	if ((pos - map->x - 1) >= 0 && pos % map->x && map->cells[pos - map->x - 1].val[0] != ' ') // top left
	{
		map->cells[pos - map->x - 1].val[0] = map->cells[pos - map->x - 1].hidden_val;
		if (map->cells[pos - map->x - 1].val[0] == '0')
			map_partial_display(map, (pos - map->x - 1));
	}
	if ((pos - map->x + 1) >= 0 && (pos + 1) % map->x && map->cells[pos - map->x + 1].val[0] != ' ') // top right
	{
		map->cells[pos - map->x + 1].val[0] = map->cells[pos - map->x + 1].hidden_val;
		if (map->cells[pos - map->x + 1].val[0] == '0')
			map_partial_display(map, (pos - map->x + 1));
	}
	if ((pos + map->x + 1) < (map->x * map->y) && (pos + 1) % map->x && map->cells[pos + map->x + 1].val[0] != ' ') // bottom right
	{
		map->cells[pos + map->x + 1].val[0] = map->cells[pos + map->x + 1].hidden_val;
		if (map->cells[pos + map->x + 1].val[0] == '0')
			map_partial_display(map, (pos + map->x + 1));
	}
	if ((pos + map->x - 1) < (map->x * map->y) && pos % map->x && map->cells[pos + map->x - 1].val[0] != ' ') // bottom right
	{
		map->cells[pos + map->x - 1].val[0] = map->cells[pos + map->x - 1].hidden_val;
		if (map->cells[pos + map->x - 1].val[0] == '0')
			map_partial_display(map, (pos + map->x - 1));
	}
}

static void	map_sides_disp(t_map *map, int pos)
{
	if ((pos - map->x) >= 0 && map->cells[pos - map->x].val[0] != ' ') // top
	{
		map->cells[pos - map->x].val[0] = map->cells[pos - map->x].hidden_val;
		if ((map->cells[pos - map->x].val[0]) == '0')
			map_partial_display(map, (pos - map->x));
	}
	if ((pos + map->x) < (map->x * map->y) && map->cells[pos + map->x].val[0] != ' ') // bottom
	{
		map->cells[pos + map->x].val[0] = map->cells[pos + map->x].hidden_val;
		if ((map->cells[pos + map->x].val[0]) == '0')
			map_partial_display(map, (pos + map->x));
	}
	if ((pos) % map->x && map->cells[pos - 1].val[0] != ' ') // left
	{
		map->cells[pos - 1].val[0] = map->cells[pos - 1].hidden_val;
		if ((map->cells[pos - 1].val[0]) == '0')
			map_partial_display(map, (pos - 1));
	}
	if ((pos + 1) % map->x && map->cells[pos + 1].val[0] != ' ') // right
	{
		map->cells[pos + 1].val[0] = map->cells[pos + 1].hidden_val;
		if ((map->cells[pos + 1].val[0]) == '0')
			map_partial_display(map, (pos + 1));
	}
}

void	map_partial_display(t_map *map, int pos)
{
	map->cells[pos].val[0] = ' ';
	map_sides_disp(map, pos);
	map_angles_disp(map, pos);
}
