/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/13 15:23:22 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	respuesta(int x);

int	main(void)
{
	ft_printf("PID Padre: %d\n", getpid());
	while (42)
	{
		signal(SIGUSR1, respuesta);
	}
}

void	respuesta(int x)
{
	ft_printf("PID Respuesta: %d, %d\n", getpid(), x);
}
