/*
** EPITECH PROJECT, 2018
** print
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void	print_map(t_map *map)
{
	int	row = 0;
	int	col = 0;
	int	i = 0;
	char	msg[] = "Please resize me";

	getmaxyx(stdscr, row, col);
	while (map->line > (row - 1) || map->col > (col - 1)) {
		getmaxyx(stdscr, row, col);
		mvprintw(row / 2, (col - my_strlen(msg)) / 2, "%s", msg);
		refresh();
	}
	while (i != map->line) {
		getmaxyx(stdscr, row, col);
		mvprintw(((row - map->line - 1) / 2) + i,
		(col - map->col) / 2, "%s\n", map->map[i]);
		refresh();
		i++;
	}
}