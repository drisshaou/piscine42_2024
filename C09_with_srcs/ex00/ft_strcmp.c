/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:02:02 by drhaouha          #+#    #+#             */
/*   Updated: 2024/02/12 17:39:30 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*int	main(int argc, char *argv[])
{
           int res1;
	   int res2;


           if (argc == 3){
               res1 = strcmp(argv[1], argv[2]);
	       res2 = ft_strcmp(argv[1], argv[2]);
	   }
           //else
               //res1 = strncmp(argv[1], argv[2], atoi(argv[3]));

           if (res1 == 0) {
               printf("strcmp <str1> and <str2> are equal\n");
               //if (argc > 3)
                   //printf(" in the first %d bytes\n", atoi(argv[3]));
               //printf("\n");
           } else if (res1 < 0) {
               printf("strcmp <str1> is less than <str2> (%d)\n", res1);
           } else {
               printf("strcmp <str1> is greater than <str2> (%d)\n", res1);
           }



           if (res2 == 0) {
               printf("ft_strcmp <str1> and <str2> are equal\n");
           } else if (res2 < 0) {
               printf("ft_strcmp <str1> is less than <str2> (%d)\n", res2);
           } else {
               printf("ft_strcmp <str1> is greater than <str2> (%d)\n", res2);
           }



	//exit(1);
}*/
