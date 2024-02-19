/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:26:28 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/12 18:38:54 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*int main(void){
	char dest[100];
	char src[11] = "abcdefghijk";
        char dest1[100];

	//printf("before dest: %s\n", dest);
        //printf("before dest1: %s\n", dest1);

        strncpy(dest1, src, 8);
        printf("strncpy dest1: %s\n", dest1);

	ft_strncpy(dest, src, 8);
	printf("ft_strncpy dest: %s\n", dest);
	
	printf("cmp: %d\n", strcmp(dest1,dest));
	
}*/
