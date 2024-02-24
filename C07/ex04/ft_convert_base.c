/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:55:01 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/21 16:55:04 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	get_size(long nbr, int base_len);
int	get_char_index(char c, char *base_from);

char	*long_to_base(long nbr, char *base, int base_len)
{
	int		i;
	char	*str;

	i = get_size(nbr, base_len);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	if (nbr == 0)
		str[0] = base[0];
	while (nbr > 0)
	{
		str[i] = base[nbr % base_len];
		nbr /= base_len;
		i--;
	}
	return (str);
}

int	get_int_value(char *nbr, char *base, int base_len)
{
	int	sign;
	int	nb;
	int	index;
	int	i;

	i = 0;
	nb = 0;
	sign = 1;
	index = -1;
	while (nbr[i] != '\0' && (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13)))
		i++;
	i -= 1;
	while (nbr[++i] != '\0' && (nbr[i] == '-' || nbr[i] == '+'))
		if (nbr[i] == '-')
			sign *= -1;
	while (nbr[i] != '\0')
	{
		index = get_char_index(nbr[i], base);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_len;
	int		to_len;
	int		value;
	char	*str;

	from_len = 0;
	while (base_from[from_len] != '\0')
		from_len++;
	to_len = 0;
	while (base_to[to_len] != '\0')
		to_len++;
	if (!is_base_valid(base_from, from_len) || !is_base_valid(base_to, to_len))
		return (NULL);
	value = get_int_value(nbr, base_from, from_len);
	str = long_to_base((long)value, base_to, to_len);
	return (str);
}
/*int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef",
	 "0123456789"));

	printf("-2a:%s\n", ft_convert_base("   -42", "0123456789",
	 "0123456789abcdef"));

	printf("-1000:%s\n", ft_convert_base("   ---1000", "0123456789",
	 "0123456789"));

	printf("-2147483648:%s\n", ft_convert_base("-2147483648",
	 "0123456789", "0123456789"));

	// printf("strlen: %lu\n", strlen(ft_convert_base("-2147483648",
	 "0123456789", "0123456789")));

	printf("-2147483648:%s\n", ft_convert_base("-80000000",
	 "0123456789abcdef", "0123456789"));
}*/