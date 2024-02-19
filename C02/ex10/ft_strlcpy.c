/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:13:56 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/12 19:26:58 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	j;

	len = ft_strlen(src);
	if (size != 0)
	{
		j = 0;
		while (j < size - 1 && src[j] != '\0')
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (len);
}
/*int main(void){
	char src[10] = "asdfghyuio";
	char dest1[10];

	printf("ft_strlcpy: %d\n", ft_strlcpy(dest1, src, 5));
	printf("strlcpy %ld\n", strlen(src));
}*/
