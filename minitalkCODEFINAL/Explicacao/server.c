#include "minitalk.h"
// Inclui definições e funções auxiliares (libft, structs, etc.)

static t_data g_data;
// Variável global (1 única) contendo client PID, bit counter e caractere em construção

// Função que trata sinais recebidos (SIGUSR1/SIGUSR2)
static void handle_bit(int sig, siginfo_t *info, void *context)
{
    (void)context;
    // Ignora o contexto não usado (evita warning)

    if (g_data.client != info->si_pid)
    {
        // Se o sinal vem de outro cliente, reseta os dados
        g_data.client = info->si_pid;
        g_data.bits = 0;
        g_data.c = 0;
    }

    g_data.c <<= 1;
    // Avança um bit para a esquerda (preparando para receber próximo)

    if (sig == SIGUSR2)
        g_data.c |= 1;
        // Se o sinal é SIGUSR2, representa bit 1 (SIGUSR1 = 0)

    g_data.bits++;
    // Conta quantos bits já recebeu

    if (g_data.bits == 8)
    {
        // Quando tiver 8 bits (1 byte), trata o caractere completo
        if ((unsigned char)g_data.c == '\0')
        {
            write(1, "\n", 1);
            // Ao final da string, imprime newline

            kill(g_data.client, SIGUSR2);
            // Envia ack para o client: "mensagem recebida"
        }
        else
            write(1, &g_data.c, 1);
            // Imprime o caractere recebido

        g_data.bits = 0;
        g_data.c = 0;
        // Reseta para receber o próximo caractere
    }
}

int main(void)
{
    struct sigaction sa;
    // Estrutura para configurar tratamento de sinais

    ft_printf("PID: ", getpid());
    // Imprime o PID para o client saber para onde enviar

    write(1, "\n", 1);

    sa.sa_sigaction = handle_bit;
    // Define a função que tratará os sinais (com info extra)

    sa.sa_flags = SA_SIGINFO;
    // Permite acessar info->si_pid no handler

    sigemptyset(&sa.sa_mask);
    // Limpa a máscara de sinais bloqueados durante a execução do handler

    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);
    // Associa SIGUSR1 e SIGUSR2 ao handler `handle_bit`

    while (1)
        pause();
    // Fica em loop infinito esperando sinais

    return (0);
}
