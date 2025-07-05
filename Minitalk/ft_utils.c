#include "minitalk.h"

void	ft_sep_color(char pad, char sep, int width, const char *color)
{
	int	i = 0;

	ft_printf("%s", color);
	while (i++ < width)
		ft_putchar_fd(sep, 1);
	ft_printf("%s\n", NC);
}
