
#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, '\0');
	return (0);
}
