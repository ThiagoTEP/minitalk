/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:49:21 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/07 09:55:29 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data;

static void	handle_bit(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_data.client != info->si_pid)
	{
		g_data.client = info->si_pid;
		g_data.bits = 0;
		g_data.c = 0;
	}
	g_data.c <<= 1;
	if (sig == SIGUSR2)
		g_data.c |= 1;
	g_data.bits++;
	if (g_data.bits == 8)
	{
		if ((unsigned char)g_data.c == '\0')
		{
			write(1, "\n", 1);
			kill(g_data.client, SIGUSR2);
		}
		else
			write(1, &g_data.c, 1);
		g_data.bits = 0;
		g_data.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_print("PID: ", getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handle_bit;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
