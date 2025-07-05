#include "minitalk.h"

void	ft_set_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
		ft_perror_exit("sigaction() failed to handle SIGUSR1");
	if (sigaction(SIGUSR2, sa, NULL) < 0)
		ft_perror_exit("sigaction() failed to handle SIGUSR2");
}
