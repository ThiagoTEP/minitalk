# include <signal.h>
# include <unistd.h>
#include <sys/types.h>

/*
signal.h: para sigaction, kill, SIGUSR1, SIGUSR2, etc.

unistd.h: para write(), usleep(), pause()

*/



typedef struct s_data
{
	pid_t			client;
	int				bits;
	unsigned int	c;
}	

/*
Define uma estrutura chamada t_data que:

    client: guarda o PID do cliente que enviou o sinal

    bits: conta quantos bits foram recebidos até o momento (vai de 0 a 8)

    c: acumula o caractere que está sendo montado bit a bit

*/

