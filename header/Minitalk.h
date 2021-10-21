/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:28:40 by lmaujean          #+#    #+#             */
/*   Updated: 2021/09/24 11:20:03 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include "../Libft/libft.h"
# include <unistd.h>

int		send(char *line, int pid_serveur);
int		send_bin(int pid_serveur, char str);
int		valid_pid(char *pid_serveur);
void	define_user(int sig);
void	define(int sig, siginfo_t *use, void *cont);

#endif
