#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void my_handler(int signo)
{
	if(signo == SIGINT)
		printf("Recebi SIGINT (crtl+C), mas nao vou sair!\n");
}


int main(void)
{
	signal(SIGINT, my_handler);
	int i;

	i=0;
	while(i<100)
	{
		printf("Trabalhando.. \n");
		sleep(1);
		i++;
	}
	return 0;
}

