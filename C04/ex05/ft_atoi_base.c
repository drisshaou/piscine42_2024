/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:03:56 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/19 13:29:50 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	get_char_index(char c, char *base)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
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

int	get_int_value(char *str, char *base, int base_len)
{
	int	sign;
	int	nb;
	int	index;
	int	i;

	i = 0;
	nb = 0;
	sign = 1;
	index = -1;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] < 13)))
		i++;
	i -= 1;
	while (str[i++] != '\0' && (str[i] == '-' || str[i] == '+'))
		if (str[i] == '-')
			sign *= -1;
	while (str[i] != '\0')
	{
		index = get_char_index(str[i], base);
		if (index != -1)
			nb = nb * base_len + index;
		else
			return (0);
		i++;
	}
	return (nb * sign);
}

int	is_base_valid(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0' && base[i] != '+' && base[i] != '-'
		&& base[i] != ' ' && !(base[i] >= 9 && base[i] <= 13))
		i++;
	if (i < base_len || base_len < 2)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (base[++j] != '\0')
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (!is_base_valid(base, base_len))
		return (0);
	return (get_int_value(str, base, base_len));
}
/*int	main(void)
{
	printf("%d:%d\n", INT_MIN, ft_atoi_base("-2147483648", "0123456789"));
	printf("10:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}*/
