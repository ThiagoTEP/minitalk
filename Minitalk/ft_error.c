#include "minitalk.h"

void	ft_perror_exit(const char *msg)
{
	ft_printf("%sError: %s%s", RED, msg, NC);
	exit(EXIT_FAILURE);
}
