#include <unistd.h>

static void	putnbr(int n)
{
	char	c;

	if (n > 9)
		putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int	ft_print(char *str, int n)
{
	while (*str)
		write(1, str++, 1);
	putnbr(n);
	return (0);
}
