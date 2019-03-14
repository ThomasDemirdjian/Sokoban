/*
** EPITECH PROJECT, 2018
** move_player
** File description:
** 
*/

#include "../include/my.h"

void	get_player(t_map *map, t_pos *pos)
{
	int	i = 0;
	int	j = 0;

	while (i != map->line) {
		while (j != map->col) {
			if (map->map[i][j] == 'P') {
				pos->i = i;
				pos->j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ifmove_u(t_map *map, t_pos *pos)
{
	if (map->map[pos->i - 1][pos->j] == '#')
		return (-1);
	else if (map->map[pos->i - 1][pos->j] == ' ' ||
	map->map[pos->i - 1][pos->j] == 'O')
		return (move_u(map, pos, 0));
	else if ((map->map[pos->i - 1][pos->j] == 'X' &&
	map->map[pos->i - 2][pos->j] == ' ') ||
	map->map[pos->i - 2][pos->j] == 'O')
		return (move_u(map, pos, 1));
	else
		return (-1);
}

int	ifmove_d(t_map *map, t_pos *pos)
{
	if (map->map[pos->i + 1][pos->j] == '#')
		return (-1);
	else if (map->map[pos->i + 1][pos->j] == ' ' ||
	 map->map[pos->i + 1][pos->j] == 'O')
		return (move_d(map, pos, 0));
	else if ((map->map[pos->i + 1][pos->j] == 'X' &&
	map->map[pos->i + 2][pos->j] == ' ') ||
	map->map[pos->i + 2][pos->j] == 'O')
		return (move_d(map, pos, 1));
	else
		return (-1);
}

int	ifmove_l(t_map *map, t_pos *pos)
{
	if (map->map[pos->i][pos->j - 1] == ' ' ||
	map->map[pos->i][pos->j - 1] == 'O')
		return (move_l(map, pos, 0));
	else if ((map->map[pos->i][pos->j - 1] == 'X' &&
	map->map[pos->i][pos->j - 2] == ' ') ||
	map->map[pos->i][pos->j - 2] == 'O')
		return (move_l(map, pos, 1));
	else
		return (-1);
}

int	ifmove_r(t_map *map, t_pos *pos)
{
	if (map->map[pos->i][pos->j + 1] == ' ' ||
	map->map[pos->i][pos->j + 1] == 'O')
		return (move_r(map, pos, 0));
	else if ((map->map[pos->i][pos->j + 1] == 'X' &&
	map->map[pos->i][pos->j + 2] == ' ') ||
	map->map[pos->i][pos->j + 2] == 'O')
		return (move_r(map, pos, 1));
	else
		return (-1);
}