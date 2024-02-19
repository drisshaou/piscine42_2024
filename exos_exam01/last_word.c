#include <unistd.h>
#include <stdio.h>

void	last_word(char *str) {

	int	i = 0;
	while (str[i] != '\0')
		i++;
	i -= 1;
	while (str[i] == '\t' || str[i] == ' ')
		i--;
	while (i > 0) {
		if (str[i] == ' ' || str[i] == '\t')
			break;
		i--;
	}
	i += 1;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av) {
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
