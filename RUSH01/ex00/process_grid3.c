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

void	fill_the_missing_in_row2(int **tab, int row)
{
	int	nb;
	int	col;
	int	tmp_row;
	int	tmp_col;
	int	total;

	nb = 0;
	col = 0;
	total = 10;
	while (col < 4)
	{
		if (tab[row][col] == 0)
		{
			nb++;
			tmp_row = row;
			tmp_col = col;
		}
		total -= tab[row][col];
		col++;
	}
	if (nb == 1)
	{
		tab[tmp_row][tmp_col] = total;
		fill_the_fourth(tab);
	}
}

void	fill_the_missing_in_row(int **tab)
{
	int	row;

	row = -1;
	while (++row < 4)
		fill_the_missing_in_row2(tab, row);
}

void	fill_the_missing_in_col2(int **tab, int col)
{
	int	row;
	int	nb;
	int	tmp_row;
	int	tmp_col;
	int	total;

	nb = 0;
	total = 10;
	row = 0;
	while (row < 4)
	{
		if (tab[row][col] == 0)
		{
			nb++;
			tmp_row = row;
			tmp_col = col;
		}
		total -= tab[row][col];
		row++;
	}
	if (nb == 1)
	{
		tab[tmp_row][tmp_col] = total;
		fill_the_fourth(tab);
	}
}

void	fill_the_missing_in_col(int **tab)
{
	int	col;

	col = -1;
	while (++col < 4)
		fill_the_missing_in_col2(tab, col);
}

void	fill_row_col_from_bottom(int **tab, int *side2, int flip)
{
	int	col;
	int	row;

	col = 4;
	while (--col >= 0)
	{
		if (side2[col] == 4)
		{
			row = 4;
			while (--row >= 0)
			{
				if (flip)
					tab[col][row] = 4 - row;
				else
					tab[row][col] = 4 - row;
			}
		}
	}
}
