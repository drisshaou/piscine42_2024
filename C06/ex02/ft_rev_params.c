/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:17:53 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/21 10:17:56 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		while (ac > 1)
		{
			while (*av[ac - 1])
			{
				write(1, av[ac - 1], 1);
				av[ac - 1]++;
			}
			write(1, "\n", 1);
			ac--;
		}
	}
	return (1);
}