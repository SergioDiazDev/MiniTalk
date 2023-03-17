/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:18:20 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/17 13:19:55 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	respuesta(int x);
long	ft_atoi_pid(char *str);
int		*ft_decabin(int dec, int *bin);

int	main(int argc, char **argv)
{
	int		pid_server;
	int		pid_client;
	int		*bin;
	int		i;
	int		j;
	char	*aux;

	bin = malloc(sizeof(int) * 8);
	if (argc != 2)
	{
		ft_printf("Introduce el pid\n");
		return (0);
	}
	pid_server = ft_atoi_pid(argv[1]);
	pid_client = getpid();
	aux = ft_itoa(pid_client);
	ft_printf("Pid Server: %d\n", pid_server);
	ft_printf("Pid Cliente: %d\n", pid_client);
	i = -1;
	while (aux[++i])
	{
		ft_decabin(aux[i], bin);
		j = -1;
		//ft_printf("Bin = (%d)", bin[i]);
		while (++j <= 7)
		{
			usleep(500);
			if (bin[j] == 0)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
		}
	}
	signal(SIGUSR1, respuesta);
	while (42)
	;
	return (0);
}

void	respuesta(int x)
{
	(void) x;
	ft_printf("Servidor a la espera :)\n");
}

long	ft_atoi_pid(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		num += (str[i] - '0');
		num *= 10;
		i++;
	}
	return (num / 10);
}

int		*ft_decabin(int dec, int *bin)
{
	int		i;
	int		bit;
	int		aux;

	dec -= '0';
	bit = 128;
	i = -1;
	while (++i != 8)
	{
		if (dec > 0)
			aux = (dec / bit);
		else
			aux = 0;
		bin[i] = aux;
		ft_printf("%d", aux);
		if (aux && dec)
			dec -= bit;
		if (bit)
			bit /= 2;
	}
	return (bin);
}
