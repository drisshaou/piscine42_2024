#include <unistd.h>

int main(int ac, char **av)
{
	int av1_len;
	int len_find;

	if (ac > 2)
	{
		av1_len = 0;
		while (av[1][av1_len])
			av1_len++;
		len_find = 0;
		while (*(av[1]++))
			while (*(av[2]++))	
				if (*av[1] == *av[2])
				{
					len_find++;
					break ;
				}
		if (len_find == av1_len)
			write(1, av[1] - av1_len - 1, av1_len);
	}
	write(1, "\n", 1);
}

