
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include "../lib/libft/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"

# define PAUSE 100

// Cores ANSI
# define RED     "\033[0;31m"
# define GRN     "\033[0;32m"
# define YEL     "\033[0;33m"
# define BLU     "\033[0;34m"
# define MAG     "\033[0;35m"
# define CYN     "\033[0;36m"
# define NC      "\033[0m"

typedef struct s_protocol
{
	int		bits;
	int		data;
	int		received;
	char	*msg;
}	t_protocol;

// Prototypes
void	ft_set_sigaction(struct sigaction *sa);
void	ft_send_bit(pid_t pid, char bit, char pause_flag);
void	ft_send_int(pid_t pid, int num);
void	ft_send_char(pid_t pid, char c);
void	ft_perror_exit(const char *msg);
void	ft_sep_color(char pad, char sep, int width, const char *color);

#endif
