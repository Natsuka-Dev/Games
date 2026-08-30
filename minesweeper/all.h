#pragma once

typedef struct s_elem
{
	char			*val;
	char			hidden_val;
	int				pos;
}					t_elem;

typedef struct s_map
{
	int		mines;
	int		x;
	int		y;
	t_elem	*cells;
}			t_map;

// tools
int		my_atoi(char *str);
int		randint(t_map *map);
void	cells_creation(t_map *map);
void	bombs_creation(t_map *map);
void	digits_creation(t_map *map);

// map
int		arg_check(int argc, char *argv[], t_map *map);
void	map_display(t_map *map, int pos);
void	init_colors(void);
void	color_cell(char *cell, int font);
int		map_cursor(t_map *map, int *pos, char letter);
void	hidden_map_display(t_map *map, int pos);
int		done(t_map *map);
void	map_partial_display(t_map *map, int pos);
