/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:27:52 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/13 13:29:28 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex_char(unsigned char c)
{
	if (c >= 16)
	{
		print_hex_char(c / 16);
		print_hex_char(c % 16);
	}
	else
	{
		if (c <= 9)
			ft_putchar(c + '0');
		else
			ft_putchar(c - 10 + 'a');
	}
}

void	print_hex(unsigned char c)
{
	ft_putchar('\\');
	if (c < 16)
		ft_putchar('0');
	print_hex_char(c);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] > 31 && str[i] < 127))
			print_hex((unsigned char)str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*int main(void){
	char str[20] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
}*/
