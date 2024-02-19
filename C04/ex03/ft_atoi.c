/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:12:18 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/19 13:37:09 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	nb;
	int	i;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] < 13)))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
/*int main(int ac, char **av)
{
	if (ac > 1){
		printf("ft_atoi result: %d\n", ft_atoi(av[1]));
		printf("Caution real atoi do not accept 
				more than one minus and plus sign\n");
		printf("atoi result: %d\n", atoi(av[1]));
	}
}*/
