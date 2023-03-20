/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/20 13:22:49 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	signal1;

	sigemptyset(&signal1.sa_mask);
	signal1.sa_sigaction = handler_server;
	signal1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal1, NULL);
	sigaction(SIGUSR2, &signal1, NULL);
	ft_printf("PID_SERVER: %d\n", getpid());
	while (42)
		pause();
	return (0);
}

void	handler_server(int x, siginfo_t *info, void *param)
{
	static unsigned char	byte = 0;
	static int				bit = 0;

	(void) param;
	if (x == SIGUSR2)
		byte += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
