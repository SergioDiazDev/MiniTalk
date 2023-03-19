/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/19 23:34:36 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	g_byte = 0;
static int				g_bit = 0;

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
	if (x == SIGUSR2)
		g_byte += 1 << g_bit;
	g_bit++;
	if (g_bit == 8)
	{
		write(1, &g_byte, 1);
		g_bit = 0;
		g_byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
