/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:39:47 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/25 18:39:51 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	int	tmp;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb <= 9)
		{
			tmp = nb + '0';
			write(1, &tmp, 1);
			return ;
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, ft_strlen2(par[i].str));
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ft_strlen2(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
/*
// #include "../ex04/ft_stock_str.h"
// cc -Wall -Werror -Wextra ft_show_tab.c ../ex04/ft_str_to_tab.c
int main(int argc, char **argv)
{
	t_stock_str *tab;

	tab = ft_strs_to_tab(argc, argv);
	ft_show_tab(tab);
	return (0);
}*/