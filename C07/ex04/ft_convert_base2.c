/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:55:09 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/21 16:55:11 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_size(long nbr, int base_len)
{
	int		size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		size++;
	}
	return (size);
}

int	get_char_index(char c, char *base_from)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (base_from[i] != '\0')
	{
		if (c == base_from[i])
		{
			valid |= 1;
			break ;
		}
		i++;
	}
	if (valid)
		return (i);
	else
		return (-1);
}
