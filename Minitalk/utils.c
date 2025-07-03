/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:30:44 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/23 11:34:10 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	while (*s)
		ft_putchar(*s++);
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res);
}

char	*ft_strjoin_char(char *s1, char c)
{
	char	*new;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1 && s1[len])
		len++;
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(s1);
	return (new);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		i--;
	}
}
