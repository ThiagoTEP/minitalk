/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:30:44 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/26 09:42:56 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
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
	char	*new_str;
	int		s1_len;
	int		i;

	s1_len = 0;
	if (s1)
		while (s1[s1_len])
			s1_len++;
	new_str = (char *)malloc(sizeof(char) * (s1_len + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	if (s1)
		free(s1);
	return (new_str);
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
		usleep(100);
		i--;
	}
}
