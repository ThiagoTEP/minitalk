#include "minitalk.h"
// Inclui o header com ft_atoi, ft_print e definição de t_data

static volatile int g_ack = 0;
// Variável global (única permitida) usada para receber confirmação do server

static void ack_handler(int sig)
{
    (void)sig;
    g_ack = 1;
}
// Função chamada quando o servidor envia SIGUSR2 (confirmação de recebimento)

static void send_byte(pid_t pid, unsigned char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100);
        i--;
    }
}
// Envia um caractere (byte) ao servidor, bit a bit, usando sinais.
// SIGUSR1 = 0, SIGUSR2 = 1

static void send_str(pid_t pid, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        send_byte(pid, (unsigned char)str[i]);
        i++;
    }
    send_byte(pid, '\0');
}
// Envia cada caractere da string usando send_byte. Ao final, envia '\0' (fim da string)

int main(int argc, char **argv)
{
    pid_t pid;

    if (argc != 3)
        return (1);
    // Verifica se os argumentos estão corretos

    pid = ft_atoi(argv[1]);
    // Converte o PID passado como string para inteiro

    signal(SIGUSR2, ack_handler);
    // Configura o handler para o sinal de confirmação do servidor

    send_str(pid, argv[2]);
    // Envia a mensagem

    while (!g_ack)
        pause();
    // Aguarda o servidor confirmar com SIGUSR2

    return (0);
}
