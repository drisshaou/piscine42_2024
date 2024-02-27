#include <stdlib.h>
#include <stdio.h>

int	ft_size(long nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = ft_size(n);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0'; base[n % base_len]
		n /= 10;
	}
	return (str);
}