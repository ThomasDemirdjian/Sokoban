/*
** EPITECH PROJECT, 2018
** game
** File description:
** 
*/

#include "../include/my.h"

int	action_key(t_map *map, t_pos *pos, int key)
{
	if (key == KEY_UP)
		return (ifmove_u(map, pos));
	else if (key == KEY_DOWN)
		return (ifmove_d(map, pos));
	else if (key == KEY_RIGHT)
		return (ifmove_r(map, pos));
	else if (key == KEY_LEFT)
		return (ifmove_l(map, pos));
	else
		return (-1);
}

int     orga_game(t_map *map, t_pos *pos)
{
	int	key = 0;

	get_player(map, pos);
	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	while (check_end_game(map) != 0) {
		if (check_stuck(map) == -1)
			return (-1);
		print_map(map);
		refresh();
		key = getch();
		if (key == ' ')
			save_tab(map, pos, 1);
		else
			action_key(map, pos, key);
	}
	return (0);
}