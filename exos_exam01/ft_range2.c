#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	*ft_range(int start, int end)
{
	int	*tab;
	int	size;
	int	i;

	size = ft_abs(start - end);
	tab = (int *)malloc(sizeof(int) * (size + 1));
	if (!tab)
		return (0);
	// i = 0;
	// while (start < end)
	// 	tab[i++] = start++;
	// while (start > end)
	// 	tab[i++] = start--;
	// tab[i] = start;

	i = -1;
	while (++i < size + 1)
		tab[i] = start + (start < end ? i : -i);
	return (tab);
}

int	main(int ac, char **av)
{
	int	*tab;
	int	size;
	int	i;
	int	start;
	int	end;

	if (ac != 3)
		return (0);
	start = atoi(av[1]);
	end = atoi(av[2]);
	tab = ft_range(start, end);
	size = ft_abs(start - end);
	i = -1;
	while (++i < size + 1)
		printf(" tab[%i] = %i\n", i, tab[i]);
	free(tab);
	return (0);
}