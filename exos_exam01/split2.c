#include <stdlib.h>
#include <stdio.h>

int	in_charset(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_size(char *str)
{
	int	size;

	size = 0;
	while (*str)
	{
			while (*str && in_charset(*str))
				str++;
			if (*str == '\0')
				break ;
			size++;
			while (*str && !in_charset(*str))
				str++;
	}
	return (size);
}

char **ft_split(char *str)
{
		int i;
		int id;
		char **split;

		if (str == NULL || (str != NULL && !(split = (char **)malloc(sizeof(char *) * (ft_size(str) + 1)))))
			return (NULL);
		while(*str && in_charset(*str))
			str++;
		id = 0;
		while (*str)
		{
				i = 0;
				while (str[i] && !in_charset(str[i]))
					i++;
				if (!(split[id] = (char *)malloc(sizeof(char) * (i + 1))))
					return (NULL);
				i = -1;
				while (str[++i] && !in_charset(str[i]))
					split[id][i] = str[i];
				split[id][i] = '\0';
				while (str[i] && in_charset(str[i]))
					i++;
				str += i;
				id++;
		}
		split[id] = NULL;
		return (split);
}

int	main(void)
{
		int		idx;
		char	**tab;

		idx = 0;
		tab = ft_split("    The prophecy i s    true lol                   ici");
		while (idx < 7)
		{
				printf("String %d : %s\n", idx, tab[idx]);
				idx++;
		}
		return (0);
}