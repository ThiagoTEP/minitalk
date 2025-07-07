/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:49:47 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/07 09:49:52 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_ack = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	send_byte(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

static void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(pid, (unsigned char)str[i]);
		i++;
	}
	send_byte(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, ack_handler);
	send_str(pid, argv[2]);
	while (!g_ack)
		pause();
	return (0);
}
