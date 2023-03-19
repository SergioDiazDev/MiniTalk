/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/19 20:18:11 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	byte = 0;
static int	bit = 0;

int	main(void)
{
	struct sigaction	signal1;

	sigemptyset(&signal1.sa_mask);
	signal1.sa_sigaction = signal_exit;
	signal1.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &signal1, NULL);

	sigaction(SIGUSR2, &signal1, NULL);
	ft_printf("PID_SERVER: %d\n", getpid());
	while (42)
		pause();
	return (0);
}

void	signal_exit(int x, siginfo_t *info, void *param)
{
	(void) param;
	(void) info;
	// if (info->si_pid == 0)
	// 	return ;
	// if (x == SIGUSR1)
	// {
	// 	ft_printf("0\n");
	// }
	if (x == SIGUSR2)
	{
		// ft_printf("1\n");
		byte += 1 << bit;
	}
	// ft_printf("bit:(%d)\nbyte(%d)\n", bit, byte);
	bit++;
	if (bit == 8)
	{
		// ft_printf("Out:(%c)\n", byte);
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
	//kill(info->si_pid, SIGUSR1);
}

