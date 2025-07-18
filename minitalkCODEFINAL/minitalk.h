/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:48:48 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/10 09:52:21 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
//#include <sys/types.h>

typedef struct s_data
{
	pid_t			client;
	int				bits;
	unsigned int	c;
}	t_data;

int		ft_atoi(char *str);
int		ft_print(char *str, int n);

#endif
