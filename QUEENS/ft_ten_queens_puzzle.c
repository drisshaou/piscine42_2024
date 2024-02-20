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
	int	*a;
	int	*b;
	int	*c;
	int	*pos;
}	t_int;

void	print_solution(int *a, int n)
{
	int		i;
	char	chr;

	i = 0;
	while (i < n)
	{
		chr = a[i] + 48;
		write(1, &chr, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_conflict(int i, int j, t_int *tabs)
{
	int	k;
	int	conflict;

	conflict = 0;
	k = 0;
	while (k < i)
	{
		if (j == tabs->pos[k] || i + j == tabs->a[k] || i - j == tabs->b[k])
		{
			conflict = 1;
			break ;
		}
		k++;
	}
	return (conflict);
}

void	backtrack(int n, int i, t_int *tabs)
{
	int	j;
	int	conflict;

	if (i < n)
	{
		j = 0;
		while (j < n)
		{
			conflict = is_conflict(i, j, tabs);
			if (!conflict)
			{
				tabs->pos[i] = j;
				tabs->a[i] = i + j;
				tabs->b[i] = i - j;
				backtrack(n, i + 1, tabs);
			}
			j++;
		}
	}
	else
		print_solution(tabs->pos, n);
}

void	ft_ten_queens_puzzle(void)
{
	t_int	*tabs;
	int		n;

	n = 10;
	tabs = (t_int *)malloc(sizeof(t_int));
	tabs->a = (int *)malloc(n * sizeof(int));
	tabs->b = (int *)malloc(n * sizeof(int));
	// tabs->c = (int *)malloc(n * sizeof(int));
	tabs->pos = (int *)malloc(n * sizeof(int));
	backtrack(n, 0, tabs);
	free(tabs->a);
	free(tabs->b);
	// free(tabs->c);
	free(tabs->pos);
	free(tabs);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
