#include <stdio.h>
#include <stdlib.h>

long	ft_abs(long x){
	return (x < 0 ? -x : x);
}

int	*ft_range(int start, int end){
	long	size;
	long	i;
	int		*tab;

	size = ft_abs((long)start - (long)end);
	if (!(tab = (int *)malloc(size * sizeof(int) + 1)))
		return (NULL);
	if (size == 1)
		tab[0] = start;
	i = -1;
	while (++i < size + 1)
		tab[i] = start + (int)((start > end) ? -i : i);
	return (tab);
}

int	main(int ac, char **av) {

	if (ac == 3) {
		int	*tab;
		long	i = 0;
		int		start = atoi(av[1]);
		int		end = atoi(av[2]);
		long	size = ft_abs((long)start - (long)end);

		tab = ft_range(start, end);
		while (i < size) {
			printf("%i, ", tab[i]);
			i++;
		}
		printf("%i", tab[i]);
		free (tab);
	}
	return (0);
}
