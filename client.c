/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:18:20 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/14 16:02:34 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	respuesta(int x);
long	ft_atoi_pid(char *str);
char	*ft_decabin(int dec, char *bin);

int	main(int argc, char **argv)
{
	int		pid_server;
	int		pid_client;
	char	*bin;
	int		i;
	int		j;
	char	*aux;

	bin = malloc(sizeof(char) * 9);
	bin[8] = 0;
	if (argc != 2)
	{
		ft_printf("Introduce el pid\n");
		return (0);
	}
	pid_server = ft_atoi_pid(argv[1]);
	pid_client = getpid();
	aux = ft_itoa(pid_client);
	//ft_printf("Pid Cliente: %d", pid_client);
	i = -1;
	while (aux[++i])
	{
		ft_decabin(aux[i], bin);
		j = -1;
		//ft_printf("Bin = (%d)", bin[i]);
		while (++j <= 8)
		{
			usleep(1000);
			if (bin[j])
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
		}
	}
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
		num += (str[i]);
		num *= 10;
		i++;
	}
	return (num / 10);
}

char	*ft_decabin(int dec, char *bin)
{
	int		i;
	int		bit;
	int		aux;

	bit = 128;
	i = -1;
	while (++i != 8)
	{
		if (dec)
			aux = (dec / bit);
		else
			aux = 0;
		bin[i] = (dec % bit) - '0';
		ft_printf("Bin[%d] = %c/n",i, bin[i]);
		if (aux && dec)
			dec -= bit;
		if (bit)
			bit /= 2;
	}
	return (bin);
}
