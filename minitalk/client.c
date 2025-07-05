#include "minitalk.h"

static volatile sig_atomic_t g_ack_received = 0;

static void ack_handler(int signo)
{
    (void)signo;
    g_ack_received = 1;
}

static void send_char(pid_t server_pid, unsigned char c)
{
    int i = 0;

    while (i < 8)
    {
        g_ack_received = 0;

        if ((c >> i) & 1)
        {
            if (kill(server_pid, SIGUSR1) == -1)
            {
                perror("Erro: kill SIGUSR1");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (kill(server_pid, SIGUSR2) == -1)
            {
                perror("Erro: kill SIGUSR2");
                exit(EXIT_FAILURE);
            }
        }

        while (!g_ack_received)
            usleep(100);
        i++;
    }
}

int main(int argc, char *argv[])
{
    pid_t server_pid;
    char *msg;
    struct sigaction sa;
    int i;

    if (argc != 3)
    {
        ft_putstr("Uso: ./client <PID servidor> <mensagem>\n");
        return 1;
    }

    server_pid = (pid_t)atoi(argv[1]);
    if (server_pid <= 0)
    {
        ft_putstr("Erro: PID do servidor inválido\n");
        return 1;
    }

    msg = argv[2];

    sa.sa_handler = &ack_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    i = 0;
    while (msg[i] != '\0')
    {
        send_char(server_pid, (unsigned char)msg[i]);
        i++;
    }

    send_char(server_pid, '\0');
    return 0;
}
