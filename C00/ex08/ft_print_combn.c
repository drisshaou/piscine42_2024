/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:17 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/10 13:11:21 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_comb(int n)
{
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
		return ;
	}
	ft_write_comb(n / 10);
	ft_write_comb(n % 10);
}

int	ft_get_max(int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 9;
	k = 10;
	while (i < n - 1)
	{
		j += (9 - i - 1) * k;
		k *= 10;
		i++;
	}
	return (j);
}

int	ft_is_valid(int k, int n)
{
	int	j;

	j = 0;
	while (k % 10 > (k / 10) % 10)
	{
		k /= 10;
		j++;
	}
	if (k == 0 && j >= n - 1)
		return (j);
	return (0);
}

void	ft_print_combn(int n)
{
	int	i;
	int	j;

	i = 0;
	if (n < 1 || n > 9)
		return ;
	while (i <= ft_get_max(n))
	{
		j = ft_is_valid(i, n);
		if (j != 0)
		{
			if (j == n - 1)
				write(1, "0", 1);
			ft_write_comb(i);
			if (i < ft_get_max(n))
				write(1, ", ", 2);
		}
		i++;
	}
}
