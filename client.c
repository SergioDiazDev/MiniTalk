/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:18:20 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/13 16:17:00 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

long	ft_atoi_pid(char *str);
char	*ft_decabin(int dec, char *bin);

int	main(int argc, char **argv)
{
	int		pid_server;
	int		pid_client;
	char	*bin;
	int		i;
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
	i = -1;
	while (aux[++i])
	{
		ft_decabin(aux[i], bin);
		ft_printf("\n");
	}
	ft_printf("Pid del server: %d\n", pid_server);
	ft_printf("Pid del cliente: %d\n", pid_client);
	kill(pid_server, SIGUSR1);
	return (0);
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
		bin[i] = dec % bit;
		if (aux && dec)
			dec -= bit;
		if (bit)
			bit /= 2;
	}
	return (bin);
}
