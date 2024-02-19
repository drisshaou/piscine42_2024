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

void	fill_with_three(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 1 && side2[col] == 2)
		{
			if (flip)
				tab[col][3] = 3;
			else
				tab[3][col] = 3;
		}
	}
	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 2 && side2[col] == 1)
		{
			if (flip)
				tab[col][0] = 3;
			else
				tab[0][col] = 3;
		}
	}
}

void	fill_with_two_bottom(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 1 && side2[col] == 3 && tab[col][2] == 3)
		{
			if (flip)
			{
				tab[col][3] = 2;
				tab[col][1] = 1;
			}
			else
			{
				tab[3][col] = 2;
				tab[1][col] = 1;
			}
		}
	}
}

void	fill_with_two_top(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 3 && side2[col] == 1 && tab[col][1] == 3)
		{
			if (flip)
			{
				tab[col][0] = 1;
				tab[col][2] = 2;
			}
			else
			{
				tab[0][col] = 1;
				tab[2][col] = 2;
			}
		}
	}
	fill_with_two_bottom(tab, side1, side2, flip);
}

void	fill_with_one_from_bottom(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 1 && side2[col] == 3 && tab[col][1] == 2)
		{
			if (flip)
			{
				tab[col][3] = 1;
				tab[col][2] = 3;
			}
			else
			{
				tab[3][col] = 1;
				tab[2][col] = 3;
			}
		}
	}
}

void	fill_with_one_from_top(int **tab, int *side1, int *side2, int flip)
{
	int	col;

	col = -1;
	while (++col < 4)
	{
		if (side1[col] == 3 && side2[col] == 1 && tab[col][2] == 2)
		{
			if (flip)
			{
				tab[col][0] = 1;
				tab[col][1] = 3;
			}
			else
			{
				tab[0][col] = 1;
				tab[1][col] = 3;
			}
		}
	}
	fill_with_one_from_bottom(tab, side1, side2, flip);
}
