/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:16:39 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/18 09:16:44 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scrapper.h"

int	is_arg_valid(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		if (*str != '\0' && *str == ' ')
			str++;
		count++;
		if (*str != '\0' && *str >= '1' && *str <= '4')
			str++;
		if (*str != '\0' && *str != ' ')
			return (0);
	}
	if (count == 16)
		return (1);
	return (0);
}

int	check_sides_occur(int *occur)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((i == 0 || i == 3) && occur[i] > 1)
			return (0);
		if (i == 2 && occur[i] > 2)
			return (0);
		if (i == 1 && occur[i] > 3)
			return (0);
		i++;
	}
	return (1);
}

int	is_parse_valid(int *side1, int *side2)
{
	int	i;
	int	cumul;
	int	occur1[4];
	int	occur2[4];

	i = -1;
	cumul = 0;
	while (++i < 4)
	{
		occur1[i] = 0;
		occur2[i] = 0;
	}
	i = -1;
	while (++i < 4)
	{
		cumul = side1[i] + side2[i];
		if (!(cumul >= 3 && cumul <= 5))
			return (0);
		occur1[side1[i] - 1]++;
		occur2[side2[i] - 1]++;
	}
	if (!check_sides_occur(occur1) || !check_sides_occur(occur2))
		return (0);
	return (1);
}

void	parse_arg(char *s, int *side1, int *side2)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == ' ')
				i++;
		if (i < 7)
			side1[index] = s[i] - 48;
		else if (i < 15)
			side2[index] = s[i] - 48;
		while (s[i] != '\0' && s[i] >= '1' && s[i] <= '4')
				i++;
		index++;
		if (i == 7 || i == 15)
			index = 0;
	}
}

void	init_tab(int **tab)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			tab[row][col] = 0;
			col++;
		}
	row++;
	}
}
