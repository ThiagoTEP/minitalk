#include "minitalk.h"

static void	ft_client_sighandler(int sig);
static void	ft_send_msg(pid_t pid, char *msg);

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		ft_perror_exit("Usage: ./client [PID] [message]\n");
	else if (kill(ft_atoi(argv[1]), 0) < 0)
		ft_perror_exit("PID does not exist\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ft_client_sighandler;
	sa.sa_flags = SA_RESTART;
	ft_set_sigaction(&sa);
	ft_sep_color('0', '=', 28, GRN);
	ft_printf("Sending to Server\n%sPID: %d%s\n", YEL, ft_atoi(argv[1]), NC);
	ft_sep_color('0', '=', 28, GRN);
	ft_send_msg(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}

static void	ft_client_sighandler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%s*%s", YEL, NC);
	else if (sig == SIGUSR2)
	{
		ft_printf("\n");
		ft_sep_color('0', '=', 28, GRN);
		ft_printf("Message successfully sent!\n");
		ft_sep_color('0', '=', 28, GRN);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_send_msg(pid_t pid, char *msg)
{
	int		i = 0;
	int		msglen = ft_strlen(msg);

	ft_printf("%sOutbound msg's length = %d%s\n", CYN, msglen, NC);
	ft_send_int(pid, msglen);
	ft_printf("\n%sSending Message%s\n", GRN, NC);
	while (msg[i] != '\0')
		ft_send_char(pid, msg[i++]);
	ft_printf("\n");
	ft_sep_color('0', '=', 28, GRN);
	ft_printf("%sSending NULL Terminator\n", MAG, NC);
	ft_sep_color('0', '=', 28, GRN);
	ft_send_char(pid, '\0');
}

