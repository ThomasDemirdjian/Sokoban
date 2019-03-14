/*
** EPITECH PROJECT, 2018
** check_obj
** File description:
** 
*/

#include "../include/my.h"

void	init_check(t_check *check)
{
	check->x = 0;
	check->o = 0;
	check->p = 0;
}

void	fill_obj(char *str, t_check *check, t_map *map)
{
	int	i = 0;

	while (str[i]) {
		if (str[i] == 'X')
			check->x++;
		else if (str[i] == 'O')
			check->o++;
		else if (str[i] == 'P')
			check->p++;
		i++;
	}
	map->nbr_box = check->x;
}

int	check_obj(t_map *map)
{
	int i = 0;
	t_check *check = malloc(sizeof(struct s_check));

	init_check(check);
	while (i != map->line)
		fill_obj(map->map[i++], check, map);
	if (check->x != check->o || check->p != 1) {
		free(check);
		return (-1);
	}
	free(check);
	return (0);
}