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

void	print_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}

void	free_tab(int **tab, int size)
{
	while (--size >= 0)
		if (tab[size] != NULL)
			free(tab[size]);
	if (tab != NULL)
		free(tab);
}

void	free_sides(t_p *s)
{
	if (s->colup != NULL)
		free(s->colup);
	if (s->coldown != NULL)
		free(s->coldown);
	if (s->rowleft != NULL)
		free(s->rowleft);
	if (s->rowright != NULL)
		free(s->rowright);
	if (s != NULL)
		free(s);
}

void	show_tab(int **tab)
{
	int			row;
	int			col;
	char		_char;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			_char = tab[row][col] + 48;
			write(1, &_char, 1);
			write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
