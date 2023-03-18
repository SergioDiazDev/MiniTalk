/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/18 11:36:30 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag = 2;

int	main(void)
{
	char	*bin;
	int		pib_client;
	int		i;

	signal(SIGUSR1, respuesta);
	signal(SIGUSR2, respuesta2);
	i = 0;
	bin = malloc(sizeof(char) * 9);
	bin[8] = 0;
	ft_printf("PID Padre: %d\n", getpid());
	while (i < 40)
	{
		if (g_flag == 0)
		{
			bin[i] = '0';
			i++;
			g_flag = 2;
		}
		else if (g_flag == 1)
		{
			bin[i] = '1';
			i++;
			g_flag = 2;
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
	g_flag = 0;
}

void	respuesta2(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 1\n");
	g_flag = 1;
}

int	binadec(char *bin)
{
	int	i;
	int	j;
	int	bit;
	int	dec;
	int	total;

	total = 0;
	bit = 128;
	dec = 0;
	j = 0;
	i = -1;
	while (++i < 40)
	{
		if (bin[i] == '1')
			dec += bit;
		bit /= 2;
		j++;
		if (!(j % 8))
		{
			total *= 10;
			total += dec;
			bit = 128;
			dec = 0;
		}
	}
	return (total);
}
