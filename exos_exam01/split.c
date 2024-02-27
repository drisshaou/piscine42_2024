#include <stdlib.h>
#include <stdio.h>

int	in_charset(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char **ft_split(char *str)
{
		int i;
		int id;
		char **split;

		if (str == NULL || !(split = (char **)malloc(sizeof(char *) * 256))) return (NULL);
		// while (*str == ' ' || *str == '\t' || *str == '\n') str++;
		while(*str && in_charset(*str)) str++;
		id = 0;
		while (*str)
		{
				i = 0;
				// while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') i++;
				while (str[i] && !in_charset(str[i])) i++;
				if (!(split[id] = (char *)malloc(sizeof(char) * (i + 1)))) return (NULL);
				i = -1;
				// while (str[++i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') split[id][i] = str[i];
				while (str[++i] && !in_charset(str[i])) split[id][i] = str[i];
				split[id][i] = '\0';
				// while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) i++;
				while (str[i] && in_charset(str[i])) i++;
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