#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static volatile int g_ack = 0;

static void ack_handler(int sig)
{
    (void)sig;
    g_ack=1;
}

int main(void)
{
    int i = 0;

    // Captura o sinal SIGINT (CTRL+C)
    signal(SIGINT, ack_handler);

    printf("Pressione CTRL+C para ver a mensagem (sem sair)...\n");

    while (1)
    {
        printf("Trabalhando... %d\n", i++);
        sleep(1); 

        if (g_ack)
        {
            printf("PULAAAAAAAAAAAAAAA PIRATA!!\n");
            g_ack = 0;
        }
    }

    return 0;
}