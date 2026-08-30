#include <ncurses.h>
#include <stdlib.h>

#include "all.h"

#define GAME_PRESENTATION "You can move thanks to your keyboard arrows\n\n'f' -> add a flag (or remove it)\n'Space' -> Click\n'Q' -> Quit\n\nPress any Key, Good luck!\n\n\n\nYou can also create a personalised map!\n\nEx: ./minesweeper A B C\nA = lenght\nB = width\nC = percentage of mines\n\nLenght and width must be between 9 and 100(included).\nPercentage of mines must be between 5 and 40 (included).\n"
#define YOU_LOST "\nSorry but you failed! Better luck next time!\n"
#define YOU_WON(a, b) "\nCongratulations! you managed to do a %d x %d minesweeper!\n"

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
			hidden_map_display(map, pos);
			printw(YOU_LOST);
			refresh();
			napms(3000);
			break ;
		}
		map_display(map, pos);
		printw("\nYou pushed -> '%c'\n", letter);
		printw("X -> %d\nY -> %d\nMines -> %d\nPos -> %d\nHidden -> %c\n", map->x, map->y, map->mines, pos, map->cells[pos].hidden_val);
		refresh();
		napms(50); // 50 ms of pause between moves
	}
	if (done(map))
		printw(YOU_WON(map->x, map->y)); //Does this work?
	getch(); // in order to see the last printw
	endwin();
	for (int i = 0; i < (map->x * map->y); i++)
		free(map->cells[i].val);
	free (map->cells);
	free (map); // Function that frees everythins
	return (0);
}
