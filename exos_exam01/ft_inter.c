#include <unistd.h>
#include <stdio.h>

void	ft_inter(unsigned char *s1, unsigned char *s2) {
	char	chr[256] = {0};

	while (*s2)
		s2 += (!chr[(int)*s2] && chr[(int)*s2]++) || 1;
	while (*s1)
		s1 += (chr[(int)*s1] && write(1, s1, 1) && chr[(int)*s1]--) || 1;
}

int	main(int argc, char **argv) {
	if (argc == 3)
		ft_inter((unsigned char *)argv[1], (unsigned char *)argv[2]);
	write(1, "\n", 1);
	return 0;
}
