/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:42:14 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/20 12:44:16 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_int
{
	int	diagr[10];
	int	diagl[10];
	int	pos[10];
}	t_int;

void	print_solution(int pos[10])
{
	int		i;
	char	chr;

	i = 0;
	while (i < 10)
	{
		chr = pos[i] + '0';
		write(1, &chr, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_conflict(int col, int row, t_int tabs[10])
{
	int	x;
	int	conflict;

	conflict = 0;
	x = 0;
	while (x < col)
	{
		if (row == tabs->pos[x]
			|| col + row == tabs->diagr[x] || col - row == tabs->diagl[x])
		{
			conflict = 1;
			break ;
		}
		x++;
	}
	return (conflict);
}

void	backtrack(int col, t_int tabs[1])
{
	int	row;
	int	conflict;

	if (col < 10)
	{
		row = 0;
		while (row < 10)
		{
			conflict = is_conflict(col, row, tabs);
			if (!conflict)
			{
				tabs->pos[col] = row;
				tabs->diagr[col] = col + row;
				tabs->diagl[col] = col - row;
				backtrack(col + 1, tabs);
			}
			row++;
		}
	}
	else
		print_solution(tabs->pos);
}

void	ft_ten_queens_puzzle(void)
{
	t_int	tabs[1];
	backtrack(0, tabs);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
