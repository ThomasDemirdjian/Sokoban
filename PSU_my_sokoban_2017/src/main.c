/*
** EPITECH PROJECT, 2018
** main
** File description:
** 
*/

#include "../include/my.h"

void	save_tab(t_map *map, t_pos *pos, int mod)
{
	int	i = 0;

	if (mod == 0) {
		while (i != map->line) {
			map->s_map[i] = my_strcpy(map->map[i], map->s_map[i]);
			i++;
		}

	}
	else {
		while (i != map->line) {
			map->map[i] = my_strcpy(map->s_map[i], map->map[i]);
			i++;
		}
		get_player(map, pos);

	}
}

int	main(int ac, char **av)
{
	t_map	*map = malloc(sizeof(struct s_map));
	t_pos	*pos = malloc(sizeof(struct s_pos));
	int	ret_v = 0;

	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		help();
		return (0);
	}
	if (check_cara(av[1]) == -1 || check_lenline(av[1]) == -1)
		return (84);
	get_map(map, av[1]);
	if (valid_wall(map) != 0 || check_obj(map) != 0)
		return (84);
	save_tab(map, pos, 0);
	ret_v = orga_game(map, pos);
	endwin();
	if (ret_v == -1)
		return (1);
	return (0);
}