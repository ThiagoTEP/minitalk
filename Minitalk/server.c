/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:29:48 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/26 10:59:05 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static char	c = 0;
	static int	bit = 0;
	static char	*msg = NULL;

	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			if (msg)
			{
				ft_putstr(msg);
				free(msg);
			}
			write(1, "\n", 1);
			fflush(stdout);
			msg = NULL;
		}
		else
			msg = ft_strjoin_char(msg, c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid_val;
	char	*pid_str;

	pid_val = getpid();
	pid_str = ft_itoa(pid_val);
	ft_putstr("Server PID: ");
	if (pid_str)
	{
		ft_putstr(pid_str);
		free(pid_str);
	}
	else
	{
		ft_putstr("[Error converting PID to string]\n");
	}
	ft_putchar('\n');
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
