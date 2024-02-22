/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:18:14 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/21 10:18:17 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_arg(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	int		i;
	char	*tmp;

	if (ac > 1)
	{
		i = 0;
		ac--;
		while (++i < ac)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0 && i < ac)
			{
				tmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tmp;
				if (i == ac - 1)
					ac--;
				i = 0;
			}
		}
		i = 0;
		while (av[++i])
			print_arg(av[i]);
	}
	return (1);
}
