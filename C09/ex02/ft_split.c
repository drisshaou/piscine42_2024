/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:55:26 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/28 08:28:27 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int	ft_fill_tab(char *str, char **tab, int index, char *charset)
{
	char		*char_tmp;
	int			len;
	int			k;

	len = 0;
	while (str[len] && !ft_in_charset(str[len], charset))
		len++;
	char_tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (char_tmp == NULL)
		return (0);
	k = -1;
	while (str[++k] && !ft_in_charset(str[k], charset))
		char_tmp[k] = str[k];
	char_tmp[k] = '\0';
	tab[index] = char_tmp;
	return (1);
}

int	ft_get_size(char *str, char *charset)
{
	int	size;

	size = 0;
	while (*str)
	{
		while (*str && ft_in_charset(*str, charset))
			str++;
		if (*str == '\0')
			break ;
		size++;
		while (*str && !ft_in_charset(*str, charset))
			str++;
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		index;

	index = 0;
	while (*str && ft_in_charset(*str, charset))
		str++;
	tab = (char **)malloc(sizeof(char *) * (ft_get_size(str, charset) + 1));
	if (tab == NULL)
		return (0);
	while (*str)
	{
		if (ft_fill_tab(str, tab, index, charset))
		{
			while (*str && !ft_in_charset(*str, charset))
				str++;
			while (*str && ft_in_charset(*str, charset))
				str++;
			index++;
		}
	}
	tab[index] = 0;
	return (tab);
}
/*int main(int ac, char **av)
{
	char **tab;
	int	i;

	if (ac > 2)
	{
		tab = ft_split(av[1], av[2]);
		i = 0;
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
	return (0);
}*/
