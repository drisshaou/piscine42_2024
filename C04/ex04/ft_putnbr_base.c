/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:44:39 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/15 11:39:25 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_hex_char(int nbr, char *base, int base_len)
{
	if (nbr >= base_len)
	{
		print_hex_char(nbr / base_len, base, base_len);
		print_hex_char(nbr % base_len, base, base_len);
	}
	else
		write(1, &base[nbr], 1);
}

int	is_base_valid(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0' && base[i] != '+' && base[i] != '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (!is_base_valid(base, base_len))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	print_hex_char(nbr, base, base_len);
}
/*int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
        write(1, "\n101010:", 8);
        ft_putnbr_base(42, "01");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n17:", 4);
	ft_putnbr_base(42, "\t0123456789abcdef");

}*/
