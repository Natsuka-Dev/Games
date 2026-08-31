#include <ncurses.h>

#include "../all.h"

#define MY_FONT 0
#define MY_BLUE 20
#define MY_GREEN 21
#define MY_RED 22
#define MY_PURPLE 23
#define MY_BROWN 24
#define MY_CYAN 25
#define MY_BLACK 26
#define MY_GREY 27
#define MY_WHITE 28

static void init_pairs(void)
{
	init_pair(0, MY_WHITE, MY_FONT);
	init_pair(1, MY_FONT, MY_WHITE);
	init_pair(2, MY_BLUE, MY_FONT); // color 1
	init_pair(3, MY_BLUE, MY_WHITE);
	init_pair(4, MY_GREEN, MY_FONT); // color 2
	init_pair(5, MY_GREEN, MY_WHITE);
	init_pair(6, MY_RED, MY_FONT); // color 3
	init_pair(7, MY_RED, MY_WHITE);
	init_pair(8, MY_PURPLE, MY_FONT); // color 4
	init_pair(9, MY_PURPLE, MY_WHITE);
	init_pair(10, MY_BROWN, MY_FONT); // color 5
	init_pair(11, MY_BROWN, MY_WHITE);
	init_pair(12, MY_CYAN, MY_FONT); // color 6
	init_pair(13, MY_CYAN, MY_WHITE);
	init_pair(14, MY_BLACK, MY_FONT); // color 7
	init_pair(15, MY_BLACK, MY_WHITE);
	init_pair(16, MY_GREY, MY_FONT); // color 8
	init_pair(17, MY_GREY, MY_WHITE);
	init_pair(18, MY_WHITE, MY_RED); // defeat color
}

void init_colors(void)
{
	start_color();
	init_color(MY_FONT, 98, 98, 98);
	init_color(MY_BLUE, 0, 0, 1000);
	init_color(MY_GREEN, 0, 1000, 0);
	init_color(MY_RED, 1000, 0, 0);
	init_color(MY_PURPLE, 700, 300, 1000);
	init_color(MY_BROWN, 600, 300, 100);
	init_color(MY_CYAN, 0, 502, 502);
	init_color(MY_BLACK, 0, 0, 0);
	init_color(MY_GREY, 502, 502, 502);
	init_color(MY_WHITE, 1000, 1000, 1000);
	init_pairs();
}

void color_cell(char cell, int font)
{
	int i;
	char str[2] = {cell, 0};

	i = 0;
	if (cell == '.' || cell == '*' || cell == ' ')
		i = 0;
	else
		i = cell - '0';
	attron(COLOR_PAIR(i * 2 + font));
	printw("%s", str);
	attroff(COLOR_PAIR(i * 2 + font));
}
