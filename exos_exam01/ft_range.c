#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int x){
	return (x < 0 ? -x : x);
}

int	*ft_range(int start, int end){
	int	size;
	int	i;
	int	*tab;

	size = ft_abs(end - start) + 1;
	if (!(tab = malloc(size * sizeof(int))))
		return (0);
	if (size == 1)
		tab[0] = start;
	i = -1;
	while (++i < size)
		tab[i] = start + ((start > end) ? -i : i);
	return (tab);
}
int	main(int ac, char **av) {

	if (ac == 3) {
		int	*tab;
		int	i = 0;
		int	start = atoi(av[1]);
		int	end = atoi(av[2]);
		int	size = ft_abs(end - start) + 1;

		tab = ft_range(start, end);
		while (i < size) {
			printf("%i, ", tab[i]);
			i++;
		}
	}
	return (0);
}
