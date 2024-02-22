/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:52:59 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/21 16:53:01 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int range)
{
	if (range < 0)
		return (-range);
	return (range);
}

int	*ft_range(int min, int max)
{
	int	*tab;
	int i;
	int	size;

	size = ft_abs(max - min);
	tab = (int *)malloc(size * sizeof(int));
	if (tab == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
