/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:54:22 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/21 16:54:25 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_get_size(char **strs, char *sep, int size)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size && strs[i])
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	total_len++;
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		total_len;

	total_len = ft_get_size(strs, sep, size);
	str = (char *)malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (0);
	i = 0;
	while (i < size && strs[i])
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	if (size == 0)
		str[0] = '\0';
	return (str);
}
/*int	main(int argc, char **argv)
{
	(void)argc;
	char *str;

	// printf("./ex03/output___said___this___is___a___success :\n");
	// printf("%s\n",  ft_strjoin(--argc, ++argv, "___"));
	str = ft_strjoin(5, ++argv, "___");
	printf("%s\n",  str);
	free(str);
}*/