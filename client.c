#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Introduce el pid\n");
		return 0;
	}
	int pid = atoi(argv[1]);
	kill(pid, 0);
	return (0);
}