/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:34:29 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/26 08:36:23 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
int		ft_atoi(const char *str);
void	send_char(pid_t pid, char c);
char	*ft_strjoin_char(char *s, char c);
char	*ft_itoa(int n);

#endif
