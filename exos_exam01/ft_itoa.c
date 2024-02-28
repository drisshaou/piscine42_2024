#include <stdlib.h>
#include <stdio.h>

int	ft_size(long n){
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0){
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	n = (long)nb;
	i = ft_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

int	main(int ac, char **av)
{
	char	*str;
	(void)ac;

	if (ac == 2)
	{
		str = ft_itoa(atoi(av[1]));
		printf("ft_itoa result: %s\n", str);
		free(str);
	}
	return (0);
}

/*
#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
        int len;
        int id;
        char **split;

        id = 0;
        if (str == NULL || !(split = (char **)malloc(sizeof(char *) * 256)))
                return (NULL);
        while (*str == ' ' || *str == '\t' || *str == '\n')
                str++;
        while (*str)
        {
                len = 0;
                while (str[len] && str[len] != ' ' && str[len] != '\t' && str[len] != '\n')
                        len++;
                //printf("len: %d, str: %s\n", len, str);
                if (!(split[id] = (char *)malloc(sizeof(char) * (len + 1))))
                        return (NULL);
                while (*str && *str != ' ' && *str != '\t' && *str != '\n')
                {
                        //printf("%c", *str);
                        split[id][0] = *str;
                        printf("%c", split[id][0]);
                        split[id]++;
                        str++;
                }
                *split[id] = '\0';
                printf("\n");
                while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
                        str++;
                id++;
        }
        split[id] = NULL;
        return (split);
}

int     main(void)
{
        int             idx;
        char    **tab;

        idx = 0;
        tab = ft_split("    The prophecy i s    true lol                   ici");
        while (idx < 7)
        {
                printf("String %d : %s\n", idx, tab[idx]);
                idx++;
        }
        return (0);
}
*/