#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Introduce el pid\n");
		return (0);
	}
	int pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}

char	*ft_decabin(int dec)
{
	char	*bin;
	int		aux;
	int		k;

	aux = dec;
	k = 1;
	while (aux / dec)
		k++;
	k *= 8;
	bin = malloc(sizeof(char) * (k + 1));
	if (!bin)
		return (0);
	k++;
	while (k--)
		bin[k] = 0;

	return (bin);
}

int	ft_convert(char *bin, int dec)
{
	
}