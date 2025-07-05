
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
