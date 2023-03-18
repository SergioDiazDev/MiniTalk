/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:15:00 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/18 11:35:56 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

//Server
void	respuesta(int x);
void	respuesta2(int x);
int		binadec(char *bin);
//Client
void	respuesta(int x);
long	ft_atoi_pid(char *str);
int		*ft_decabin(int dec, int *bin);
#endif
