/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/17 13:19:08 by sdiaz-ru         ###   ########.fr       */
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
int 	flag = 2;
int	main(void)
{
	char *bin;
	int	pib_client;
	int	i;

	signal(SIGUSR1, respuesta);
	signal(SIGUSR2, respuesta2);
	i  = 0;
	bin = malloc(sizeof(char) * 9);
	bin[8] = 0;
	ft_printf("PID Padre: %d\n", getpid());
	while (i < 40)
	{
		if (flag == 0)
		{
			bin[i] = '0';
			i++;
			flag = 2;
		}
		else if (flag == 1)
		{
			bin[i] = '1';
			i++;
			flag = 2;
		}
	}
	pib_client = binadec(bin);
	ft_printf("Pid Client: %d\n", pib_client);
	ft_printf("Pid Client: %s\n", bin);
	kill(pib_client, SIGUSR1);
}

void	respuesta(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 0\n");
	flag = 0;
}

void	respuesta2(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 1\n");
	flag = 1;
}

int	binadec(char *bin)
{
	int i;
	int j = 0;
	int bit;
	int dec;
	int total = 0; 

	bit = 128;
	dec = 0;
	i = -1;
	while (++i < 40)
	{
		if (bin[i] == '1')
			dec += bit;
		bit /= 2;	
		j++;
		if(!(j % 8))
		{
			total *= 10;
			total += dec;
			bit = 128;
			dec = 0;
		}

	}
	return (total);
}