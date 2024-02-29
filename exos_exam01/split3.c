#include <stdlib.h>
#include <stdio.h>

int	in_charset(char c){
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_size(char *str){
	int	count;

	count = 0;
	while (*str){
		while (*str && in_charset(*str) && str++);
		if (*str == '\0')
			break ;
		count++;
		while (*str && !in_charset(*str) && str++);
	}
	return (count);
}

char	**ft_split(char *str){
	char	**tab;
	int	i;
	int	id;

	if (str == NULL || (str != NULL && !(tab = (char **)malloc(sizeof(char *) * (ft_size(str) + 1)))))
		return (NULL);
	while ((*str && in_charset(*str) && str++) || (id = 0) != 0);
	while (*str){
		i = -1;
		while (str[++i] && !in_charset(str[i]));
		if (!(tab[id] = (char *)malloc(sizeof(char) * (i + 1 ))) || (i = -1) == 0)
			return (NULL);
		while ((str[++i] && !in_charset(str[i])) && (tab[id][i] = str[i]));
		tab[id++][i] = '\0';
		while (str[i] && in_charset(str[i]) && i++);
		str += i;
	}
	tab[id] = 0;
	return (tab);
}

int	main(int ac, char **av){
	char	**tab;
	int	i;

	if (ac == 2){
		tab = ft_split(av[1]);
		i = 0;
		while(tab[i]){
			printf("%s\n", tab[i]);
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (0);
}
