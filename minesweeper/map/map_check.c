#include <unistd.h>

#include "../all.h"

#define ARGC_PROBLEM "There is a wrong number of arguments.\n1: Lenght\n2: Width\n3: Percentage of mines (from 5 included to 40 included)\n"
#define WRONG_AMOUT_OF_MINES "The percentage of mines must be from 5 included to 40 included\n"
#define WRONG_X "The Lenght must be from 9 included to 100 included\n"
#define WRONG_Y "The Width must be from 9 included to 100 included\n"
#define DEFAULT_MINES 13
#define DEFAULT_X 9
#define DEFAULT_Y 9

static int errors(int argc, char *argv[])
{
	if (argc != 4)
	{
		write(1, ARGC_PROBLEM, 114);
		return (0);
	}
	if (!(my_atoi(argv[1]) > 8 && my_atoi(argv[1]) < 101))
	{
		write(1, WRONG_X, 51);
		return (0);
	}
	if (!(my_atoi(argv[2]) > 8 && my_atoi(argv[2]) < 101))
	{
		write(1, WRONG_Y, 50);
		return (0);
	}
	if (!(my_atoi(argv[3]) > 4 && my_atoi(argv[3]) < 41))
	{
		write(1, WRONG_AMOUT_OF_MINES, 63);
		return (0);
	}
	return (1);
}

int	arg_check(int argc, char *argv[], t_map *map)
{
	if (argc != 1 && (!(errors(argc, argv))))
		return (0);
	if (argc == 1)
	{
		map->mines = DEFAULT_MINES;
		map->x = DEFAULT_X;
		map->y = DEFAULT_Y;
	}
	else
	{
		map->x = my_atoi(argv[1]);
		map->y = my_atoi(argv[2]);
		map->mines = my_atoi(argv[3]);
	}
	map->mines = (map->x * map->y * map->mines) / 100;
	return (1);
}

int	done(t_map *map) // WRONG
{
	for (int i = 0; i < (map ->x * map->y); i++)
	{
		if (map->cells[i].val == '.')
			return (0);
	}
	return (1);
}
