/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:15:00 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/20 13:28:56 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

//Server
void	handler_server(int x, siginfo_t *info, void *param);
//Client
void	handler_client(int x);
long	ft_atoi_pid(char *str);
#endif
