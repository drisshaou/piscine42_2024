/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:39:34 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/18 20:39:41 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scrapper.h"

void	start(int **tab, t_p *s)
{
	init_tab(tab);
	fill_row_col_from_top(tab, s->colup, s->coldown, 0);
	fill_row_col_from_top(tab, s->rowleft, s->rowright, 1);
	fill_with_four(tab, s->colup, s->coldown, 0);
	fill_with_four(tab, s->rowleft, s->rowright, 1);
	fill_with_three(tab, s->colup, s->coldown, 0);
	fill_with_three(tab, s->rowleft, s->rowright, 1);
	fill_with_one_from_top(tab, s->colup, s->coldown, 0);
	fill_with_one_from_top(tab, s->rowleft, s->rowright, 1);
	fill_with_two_top(tab, s->colup, s->coldown, 0);
	fill_with_two_top(tab, s->rowleft, s->rowright, 1);
	fill_the_fourth(tab);
	if (is_tab_valid(tab))
		show_tab(tab);
	free_tab(tab, 4);
	free_sides(s);
}

int	parsing(t_p *s, char *av)
{
	s->colup = (int *)malloc(sizeof(int) * 4);
	s->coldown = (int *)malloc(sizeof(int) * 4);
	s->rowleft = (int *)malloc(sizeof(int) * 4);
	s->rowright = (int *)malloc(sizeof(int) * 4);
	parse_arg(av, s->colup, s->coldown);
	parse_arg(av + 16, s->rowleft, s->rowright);
	if (!is_parse_valid(s->colup, s->coldown)
		|| !is_parse_valid(s->rowleft, s->rowright))
		return (0);
	return (1);
}

int	allocate_memory(char *av)
{
	int	**tab;
	int	row;
	t_p	*s;

	s = (t_p *)malloc(sizeof(t_p));
	tab = (int **)malloc(sizeof(int) * (4 * 4));
	if (s == NULL || !parsing(s, av) || tab == NULL)
	{
		free_sides(s);
		return (0);
	}
	row = -1;
	while (++row < 4)
	{
		tab[row] = (int *)malloc(sizeof(int) * 4);
		if (tab[row] == NULL)
		{
			free_sides(s);
			free_tab(tab, row + 1);
			return (0);
		}
	}
	start(tab, s);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!is_arg_valid(av[1]) || !allocate_memory(av[1]))
		{
			print_error();
			return (0);
		}
	}
	else
		print_error();
	return (0);
}
