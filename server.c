/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/14 15:40:44 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	respuesta(int x);
void	respuesta2(int x);
int		binadec(char *bin);

int	main(void)
{
	char *bin;
	int	pib_client;
	int	i;

	i  = 0;
	bin = malloc(sizeof(char) * 9);
	bin[8] = 0;
	ft_printf("PID Padre: %d\n", getpid());
	while (i <= 8)
	{
		signal(SIGUSR2, respuesta2);
		if (!signal(SIGUSR1, respuesta))
		{
			bin[i] = 0;
			i++;
		}
		else if (!signal(SIGUSR2, respuesta2))
		{
			bin[i] = 1;
			i++;
		}
		printf("\n%d\n", getpid());
	}
	pib_client = binadec(bin);
	ft_printf("Pid Client: %s\n", bin);
	kill(pib_client, SIGUSR2);
}

void	respuesta(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 0\n");
}

void	respuesta2(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 1\n");
}

int	binadec(char *bin)
{
	int i;
	int bit;
	int dec;

	bit = 128;
	dec = 0;
	i = -1;
	while (++i <=8)
	{
		if (bin[i])
			dec += bit;
		bit /= 2; 
	}
	return (dec);
}