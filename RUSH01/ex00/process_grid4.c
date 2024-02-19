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

void	fill_row_col_from_top(int **tab, int *side1, int *side2, int flip)
{
	int	col;
	int	row;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 4)
		{
			row = -1;
			while (++row < 4)
			{
				if (flip)
					tab[col][row] = row + 1;
				else
					tab[row][col] = row + 1;
			}
		}
	}
	fill_row_col_from_bottom(tab, side2, flip);
}

int	is_tab_valid(int **tab)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tab[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
