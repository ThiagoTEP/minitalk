/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:33:18 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/23 11:34:19 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
