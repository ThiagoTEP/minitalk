#include "minitalk.h"

static char g_message[BUFFER_SIZE];
static int g_bit_index = 0;
static int g_char_index = 0;

static void reset_message(void)
{
    int i = 0;
    while (i < BUFFER_SIZE)
    {
        g_message[i] = 0;
        i++;
    }
    g_bit_index = 0;
    g_char_index = 0;
}

static void handle_signal(int signo, siginfo_t *info, void *context)
{
    (void)context;
    static unsigned char current_char = 0;

    if (signo == SIGUSR1)
        current_char |= (1 << g_bit_index);

    g_bit_index++;

    if (g_bit_index == 8)
    {
        g_message[g_char_index] = current_char;
        g_char_index++;

        if (current_char == '\0' || g_char_index >= BUFFER_SIZE - 1)
        {
            ft_putstr(g_message);
            ft_putchar('\n');
            reset_message();
        }
        current_char = 0;
        g_bit_index = 0;
    }

    if (kill(info->si_pid, SIGUSR1) == -1)
        ft_putstr("Erro: falha ao enviar sinal de confirmação\n");
}

int main(void)
{
    struct sigaction sa;

    reset_message();

    sa.sa_sigaction = &handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction SIGUSR1");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("sigaction SIGUSR2");
        exit(EXIT_FAILURE);
    }

    ft_putstr("Server PID: ");
    ft_putnbr(getpid());
    ft_putchar('\n');

    while (1)
        pause();

    return 0;
}
