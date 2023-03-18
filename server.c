/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/18 13:34:58 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

siginfo_t *info;

int	main(void)
{
	int			pib_client;
	struct sigaction sa;
	//sa.__sigaction_u.__sa_sigaction(SIGUSR1, info,);
	sa.__sigaction_u.__sa_handler = signal_exit;
	signal(SIGUSR1, sa.__sigaction_u.__sa_handler);
	while (42)
	{
		ft_printf("PID_SERVER: %d\n",getpid());
	}
	kill(pib_client, SIGUSR1);
}

void	signal_exit(int x)
{
	ft_printf("PID Respuesta: %d\n", x);
	ft_printf("%s\n", info->si_pid);
	exit(0);
}

void	respuesta2(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 1\n");
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
