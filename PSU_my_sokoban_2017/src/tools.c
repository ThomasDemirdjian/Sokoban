/*
** EPITECH PROJECT, 2018
** tools
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

char	*my_strcpy(char *src, char *dest)
{
	int	i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}