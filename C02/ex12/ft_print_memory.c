/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:32:00 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/14 18:29:35 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_char_hex(unsigned char c)
{
	char	chr1;
	char	chr2;

	chr1 = c / 16;
	chr2 = c % 16;
	if (chr1 <= 9)
		chr1 += '0';
	else
		chr1 = chr1 - 10 + 'a';
	if (chr2 <= 9)
		chr2 += '0';
	else
		chr2 = chr2 - 10 + 'a';
	write(1, &chr1, 1);
	write(1, &chr2, 1);
}

void	print_hex_addr(unsigned long addr)
{
	int		i;
	char	temp;
	char	hex[16];

	i = 0;
	while (i < 16)
		hex[i++] = '0';
	i = 15;
	while (addr > 0)
	{
		temp = (char)(addr % 16);
		if (temp <= 9)
			temp += '0';
		else if (temp <= 15)
			temp = temp - 10 + 'a';
		hex[i--] = temp;
		addr /= 16;
	}
	write(1, hex, 16);
	write(1, ": ", 2);
}

void	print_str(unsigned int start, unsigned char *str, unsigned int max)
{
	unsigned int	i;

	i = start;
	while (i < (start + 16) && i < max)
	{
		if (!(str[i] > 31 && str[i] < 127))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_line(unsigned int start, void *addr, unsigned int max)
{
	unsigned int	i;
	unsigned char	*str;

	print_hex_addr((unsigned long)addr);
	i = start;
	str = (unsigned char *)addr;
	while (i < (start + 16) && i < max)
	{
		print_char_hex((unsigned char)str[i]);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < (start + 16))
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	print_str(start, str, max);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	void			*temp_addr;

	i = 0;
	temp_addr = addr;
	while (i < size)
	{
		print_line(i, temp_addr, size);
		i += 16;
		temp_addr += 16;
	}
	return (addr);
}
/*int		main(void)
{
	char str[] = "Ceci est un test d'affichage de print memory!\nSegFault";
	ft_print_memory(str, 200);
	//char src[] = "Bonjour les aminches\n\n\nc\n est fou\ntout\nce qu o
	//n peut faire avec\n\n\nprint_memory\n\n\n\tlol\nlol\n \0";

	//ft_print_memory(src, 92);
	//printf("addr : %p\n", str);
	//print_hex_addr((unsigned long) str);
}*/
