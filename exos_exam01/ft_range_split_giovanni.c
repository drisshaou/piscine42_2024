#include <stdlib.h>

int	ft_absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	*ft_range(int start, int end)
{
	int	idx;
	int	size;
	int	*tab;

	idx = 0;
	size = ft_absolute_value(start - end);
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	while (start < end)
	{
		tab[idx] = start;
		start++;
		idx++;
	}
	tab[idx] = start;
	while (start > end)
	{
		tab[idx] = start;
		start--;
		idx++;
	}
	tab[idx] = start;
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*tab;
	int	idx;
	int	start;
	int	end;
	int	size;

	idx = 0;
	start = -5;
	end = 5;
	tab = ft_range(start, end);
	size = ft_absolute_value(end - start) + 1;
	while (idx < size)
	{
		printf(" [%i] ", tab[idx]);
		idx++;
	}
	printf("\n");
}
*/


#include <stdlib.h>


char **ft_split(char *str)
{
	int idx;
	int row;
	int column;
	char **split;

	idx = 0;
	row = 0;
	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
		idx++;
	while (str[idx] != '\0')
	{
		column = 0;
		if(!(split[row] = (char *)malloc(sizeof(char) * 4092)))
			return (NULL);
		while (str[idx] != ' ' && str[idx] != '\t' && str[idx] != '\n')
		{
			split[row][column] =  str[idx];
			column++;
			idx++;
		}
		while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
			idx++;
		split[row][column] = '\0';
		row++;
	}
	split[row] = NULL;
	return (split);
}

#include <stdio.h>

int	main(void)
{
	int		idx;
	char	**tab;

	idx = 0;
	tab = ft_split("    The prophecy i s 	true lol 		   ici");
	while (idx < 7)
	{
		printf("String %d : %s\n", idx, tab[idx]);
		idx++;
	}
	return (0);
}