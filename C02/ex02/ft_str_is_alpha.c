/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:27:57 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/12 16:46:18 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = str;
	while (s[i] != '\0')
	{
		if (!((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123)))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void){
	printf("is valid : %d\n", ft_str_is_alpha("scr1tvybdfg"));
}*/
