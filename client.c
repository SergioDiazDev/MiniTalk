/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:18:20 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/19 20:18:34 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int					count;
	int					i;
	int					pid_server;

	if (argc != 3)
		return (ft_printf("Error, introduce el PID y el mensaje.\n"));
	signal(SIGUSR1, respuesta);
	pid_server = ft_atoi_pid(argv[1]);
	//kill(pid_server, SIGUSR1);
	i = -1;
	while (argv[2][++i])
	{
		count = -1;
		//ft_printf("i=(%d)\n",i);
		while (++count != 8)
		{
			if(!((argv[2][i] >> count) & 1))
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			usleep(50);
			//pause();
		}
	}
	return (0);
}

void	respuesta(int x)
{
	(void) x;
	//ft_printf("\nPing%d\n", info->si_pid);
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
