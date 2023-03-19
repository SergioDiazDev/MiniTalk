/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/19 16:29:45 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_exit;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("PID_SERVER: %d\n", getpid());
	while (42)
		pause();

}

void	signal_exit(int x, siginfo_t *info, void *param)
{
	int i;

	i = 33;
	(void) param;
	(void) x;
	// ft_printf("PID_SERVER: %d\n", getpid());
	// ft_printf("PID Respuesta: %d\n", x);
	// ft_printf("PID: %d\n", info->si_pid);
	
	if (info->si_signo == SIGUSR1)
	{
		ft_printf("\nPong\n");
		kill(info->si_pid, SIGUSR1);
	}
	else if (info->si_signo == SIGUSR2)
	{
		ft_printf("1\n");
		kill(info->si_pid, SIGUSR1);
	}

	
}

void	respuesta2(int x)
{
	(void)x;
	ft_printf("PID Respuesta: 1\n");
}
