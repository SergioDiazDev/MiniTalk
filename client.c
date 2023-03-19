/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:18:20 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/19 13:33:50 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid_server;

	if (argc != 2)
		return (ft_printf("Introduce el pid\n"), 0);
	pid_server = ft_atoi_pid(argv[1]);
	kill(pid_server, SIGUSR1);
	signal(SIGUSR1, respuesta);
	while (42)
		;
	return (0);
}

void	respuesta(int x)
{
	(void) x;
	ft_printf("\nServidor a la espera :)\n");
	exit(-1);
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

int	*ft_decabin(int dec, int *bin)
{
	int		i;
	int		bit;
	int		aux;

	dec -= '0';
	bit = 128;
	i = -1;
	while (++i != 8)
	{
		if (dec > 0)
			aux = (dec / bit);
		else
			aux = 0;
		bin[i] = aux;
		ft_printf("%d", aux);
		if (aux && dec)
			dec -= bit;
		if (bit)
			bit /= 2;
	}
	return (bin);
}
