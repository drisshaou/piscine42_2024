/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:08:00 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/15 10:24:42 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	else
	{
		while (src[i] != '\0' && i < (size - dest_len - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}
/*int main(int ac, char **av)
{
	if (ac == 4)
	{
                //char *dest = "1234";
                //char *dest1 = "1234";
                //char *src = "ABCD";

                char dest[100] = "1234";
                char dest1[100] = "1234";
                char src[5] = "ABCD";

		//dest = strcpy(dest, av[1]);
		//dest1 = strcpy(dest1, av[1]);
		//src = strcpy(src, av[2]);
                
		printf("before ft_strlcat dest: %s\n", dest);
                printf("before strlcat dest1: %s\n", dest1);

		printf("\n\n");

		int ret = ft_strlcat(dest, src, atoi(av[3]));
		int ret1 = strlcat(dest1, src, atoi(av[3]));
		
		printf("ft_strlcat return: %d\n", ret);
		printf("strlcat return: %d\n", ret1);
		printf("after ft_strlcat dest: %s\n", dest);
		printf("after strlcat dest1: %s\n", dest1);

	}
}*/
