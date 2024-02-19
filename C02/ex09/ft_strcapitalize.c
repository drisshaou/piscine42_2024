/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:42:34 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/14 09:29:09 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_lowercase(char c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int	ft_is_alpha_numeric(char c)
{
	if (!(c > 47 && c < 58) && !(c > 64 && c < 91) && !(c > 96 && c < 123))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		if ((i > 0 && !ft_is_alpha_numeric(str[i - 1])
				&& ft_is_lowercase(str[i]))
			|| (i == 0 && ft_is_lowercase(str[i])))
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*int main(void){
char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
printf("%s\n", ft_strcapitalize(str));
}*/
