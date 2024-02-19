/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:34:06 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/10 13:10:35 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_comb(char nb1, char nb2)
{
	char	a;
	char	b;
	char	c;
	char	d;

	if (nb2 > nb1)
	{
		a = nb1 / 10 + 48;
		b = nb1 % 10 + 48;
		c = nb2 / 10 + 48;
		d = nb2 % 10 + 48;
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (nb1 != 98)
			write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	nb1;
	char	nb2;

	nb1 = 0;
	while (nb1 <= 99)
	{
		nb2 = 0;
		while (nb2 <= 99)
		{
			ft_write_comb(nb1, nb2);
			nb2++;
		}
		nb1++;
	}
}
