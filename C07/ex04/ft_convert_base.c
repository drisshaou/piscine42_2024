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
#include <limits.h>

int		get_size(int nbr, int base_len)
{
	int	size;

	size = 0;
	if (size < 0)
		size++;
	while(nbr > 0)
	{
		nbr /= base_len;
		size++;
	}
	return (size);
}

// void	print_hex_addr(unsigned long addr)
// {
// 	int		i;
// 	char	temp;
// 	char	hex[16];

// 	i = 0;
// 	while (i < 16)
// 		str[i++] = '0';
// 	i = 15;
// 	while (addr > 0)
// 	{
// 		temp = (char)(addr % 16);
// 		if (temp <= 9)
// 			temp += '0';
// 		else if (temp <= 15)
// 			temp = temp - 10 + 'a';
// 		str[i--] = temp;
// 		addr /= 16;
// 	}
// 	write(1, hex, 16);
// 	write(1, ": ", 2);
// }

char	*get_str(long nbr, char *base, int base_len, char *str)
{
	int		i;
	char	temp;

	while (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr < 16 && base_len == 16)
		str[1] = '0';
	i = get_size(nbr, base_len);
	while (i > 0)
	{
		temp = base[nbr % base_len];
		str[i--] = temp;
		nbr /= base_len;
	}
	str[get_size(nbr, base_len) - 1] = '\0';
	return (str);
}

// void	print_base_char(long nbr, char *base, int base_len, int size)
// void	print_base_char(long nbr, char *base, int base_len, char *str)
// {

// 	if (nbr >= base_len)
// 	{
// 		print_base_char(nbr / base_len, base, base_len);
// 		print_base_char(nbr % base_len, base, base_len);
// 	}
// 	else
// 		str[size]
// 		write(1, &base[nbr], 1);
// }

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

int	get_int_value(char *nbr, char *base_from, int base_len)
{
	int	sign;
	int	nb;
	int	index;
	int	i;

	i = 0;
	nb = 0;
	sign = 1;
	index = -1;
	while (nbr[i] != '\0' && (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] < 13)))
		i++;
	i -= 1;
	while (nbr[i++] != '\0' && (nbr[i] == '-' || nbr[i] == '+'))
		if (nbr[i] == '-')
			sign *= -1;
	while (nbr[i] != '\0')
	{
		index = get_char_index(nbr[i], base_from);
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
	int	base_len;
	int	int_val;
	// int	string_size;
	char *str;

	base_len = 0;
	while (base_from[base_len] != '\0')
		base_len++;
	if (!is_base_valid(base_from, base_len)
			|| !is_base_valid(base_to, base_len))
		return (0);
	int_val = get_int_value(nbr, base_from, base_len);
	base_len = 0;
	while (base_to[base_len] != '\0')
		base_len++;
	// string_size = get_size(int_val, base_len);
	// print_base_char((long)int_val, base_to, base_len, string_size);
	str = (char *)malloc(sizeof(char) * (get_size(int_val, base_len) + 1));
	if (str == NULL)
		return (0);
	str = get_str(int_val, base_to, base_len, str);
	return (str);
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
int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}