#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
	int i = (*str == ' ' || (*str >= 9 && *str <= 13)) ? 0 : 1, *j = &i;
	char *splitted[100000], *tmp = str - 1;
	splitted[0] = str;
	while (*++tmp)
		splitted[i - 1] = (*tmp = (*tmp == ' ' || (*tmp >= 9 && *tmp <= 13)) ? 0 : *tmp) && tmp != str && *(tmp - 1) == 0 ? ((*j)++, tmp) : splitted[i - 1];
	splitted[i] = 0;
	return (splitted);
}

int	main(void)
{
		int		i;
		char	**tab;

		i = 0;
		tab = ft_split("    The prophecy i s    true lol                   ici");
		while (i < 7)
		{
				printf("String %d : %s\n", i, tab[i]);
				i++;
		}
		return (0);
}