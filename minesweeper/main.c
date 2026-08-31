#include <ncurses.h>
#include <stdlib.h>

#include "all.h"

#define GAME_PRESENTATION "Welcome to my own version of the Minesweeper!\n\n'Keyboard arrows' -> Move accross the map\n'f' -> Add a flag (or remove it)\n'Space' -> Click\n'Q' -> Quit\n\n\nYou can also create personalised maps!\n\nEx: ./minesweeper A B C\nA = lenght\nB = width\nC = percentage of mines\n\nLenght and width must be between 9 and 100(included).\nPercentage of mines must be between 5 and 40 (included).\n\nPress any Key, hope you enjoy it!\n"
#define YOU_LOST "\nSorry but you failed! Better luck next time!\n"
#define YOU_WON(a, b) "\nCongratulations! you managed to do a %d x %d minesweeper!\n", a, b

int main(int argc, char *argv[])
{
	char	letter;
	t_map	*map;
	int		pos;

	letter = '\0';
	map = NULL;
	pos = 0;
	map = malloc(sizeof(*map));
	if (!map)
		return (1);
	if (!(arg_check(argc, argv, map)))
	{
		free(map);
		return (1);
	}
	cells_creation(map);
	bombs_creation(map);
	digits_creation(map);
	initscr();
	init_colors();
	printw(GAME_PRESENTATION);
	while (letter != 'Q' && !done(map))
	{
		letter = getch();
		if (map_cursor(map, &pos, letter))
		{
			map_display(map, pos, 1);
			printw(YOU_LOST);
			refresh();
			break ;
		}
		map_display(map, pos, 0);
		refresh();
		napms(25);
	}
	if (done(map))
		printw(YOU_WON(map->x, map->y));
	getch();
	endwin();
	free_all(map);
	return (0);
}
