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

void	fill_with_four1(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 3 && side2[col] == 2)
		{
			if (flip)
				tab[col][2] = 4;
			else
				tab[2][col] = 4;
		}
	}
	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 2 && side2[col] == 3)
		{
			if (flip)
				tab[col][1] = 4;
			else
				tab[1][col] = 4;
		}
	}
}

void	fill_with_four(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 1)
		{
			if (flip)
				tab[col][0] = 4;
			else
				tab[0][col] = 4;
		}
	}
	col = -1;
	while (++col < 4)
	{
		if (side2[col] == 1)
		{
			if (flip)
				tab[col][3] = 4;
			else
				tab[3][col] = 4;
		}
	}
	fill_with_four1(tab, side1, side2, flip);
}

int	is_valid(int **tab, int row, int col, int val)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (tab[row][i] == val || tab[i][col] == val)
			return (0);
	}
	return (1);
}

int	check_tab_occur(int **tab, int val)
{
	int	col;
	int	row;
	int	nb;

	row = -1;
	nb = 0;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			if (tab[row][col] == val)
				nb++;
	}
	return (nb);
}

void	fill_the_fourth(int **tab)
{
	int	col;
	int	row;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			if (is_valid(tab, row, col, 4) && check_tab_occur(tab, 4) == 3)
				tab[row][col] = 4;
			if (is_valid(tab, row, col, 3) && check_tab_occur(tab, 3) == 3)
				tab[row][col] = 3;
			if (is_valid(tab, row, col, 2) && check_tab_occur(tab, 2) == 3)
				tab[row][col] = 2;
			if (is_valid(tab, row, col, 1) && check_tab_occur(tab, 1) == 3)
				tab[row][col] = 1;
			fill_the_missing_in_col(tab);
			fill_the_missing_in_row(tab);
		}
	}
}
