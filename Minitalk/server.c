#include "minitalk.h"

static void	ft_server_sighandler(int sig, siginfo_t *info, void *context);
static void	ft_strlen_received(t_protocol *server);
static void	ft_print_msg(t_protocol *server, int *i, pid_t pid);
static void	ft_print_pid(void);

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_server_sighandler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_set_sigaction(&sa);
	ft_print_pid();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

static void	ft_server_sighandler(int sig, siginfo_t *info, void *context)
{
	static t_protocol	server;
	static int			i;

	usleep(PAUSE);
	(void)context;
	if (!server.bits)
		server.data = 0;
	if ((sig == SIGUSR2) && !server.received)
		server.data |= 1 << (((sizeof(int) * 8) - 1) - server.bits);
	else if ((sig == SIGUSR2) && server.received)
		server.data |= 1 << (((sizeof(char) * 8) - 1) - server.bits);
	++server.bits;
	ft_strlen_received(&server);
	ft_print_msg(&server, &i, info->si_pid);
	ft_send_bit(info->si_pid, 0, 0);
}

static void	ft_strlen_received(t_protocol *server)
{
	if ((server->bits == (sizeof(int) * 8)) && !server->received)
	{
		server->received = 1;
		ft_printf("%sMessage Length : %s%d\n", YEL, NC, server->data);
		server->msg = ft_calloc((server->data + 1), sizeof(char));
		if (!server->msg)
			ft_perror_exit("ft_calloc() failed\n");
		server->msg[server->data] = '\0';
		server->bits = 0;
	}
}

static void	ft_print_msg(t_protocol *server, int *i, pid_t pid)
{
	if ((server->bits == 8) && server->received)
	{
		server->msg[*i] = server->data;
		++(*i);
		if (server->data == '\0')
		{
			ft_printf("[%sMessage bytes received!%s]\n", MAG, NC);
			ft_printf("Message:\n%s%s%s\n", GRN, server->msg, NC);
			ft_print_pid();
			free(server->msg);
			server->msg = NULL;
			server->received = 0;
			*i = 0;
			ft_send_bit(pid, 1, 0);
		}
		server->bits = 0;
	}
}

static void	ft_print_pid(void)
{
	ft_sep_color('0', '=', 24, GRN);
	ft_printf("      %s« minitalk »%s\n", MAG, NC);
	ft_sep_color('0', '=', 24, GRN);
	ft_printf("« Server PID : %s%d%s »\n", YEL, getpid(), NC);
	ft_sep_color('0', '=', 24, GRN);
	ft_printf("%sListening...%s\n", CYN, NC);
}
