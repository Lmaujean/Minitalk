/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 11:19:27 by lmaujean          #+#    #+#             */
/*   Updated: 2021/10/22 01:15:55 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minitalk.h"

static int	g_wait = 0;

int	valid_pid(char *pid_serveur)
{
	int	i;

	i = 0;
	while (pid_serveur[i])
	{
		if (ft_isdigit(pid_serveur[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	send_bin(int pid_serveur, char str)
{
	int	size;

	size = 0;
	while (size < 8)
	{
		g_wait = 0;
		usleep(50);
		if ((str >> size) & 1)
		{
			if (kill(pid_serveur, SIGUSR1) == -1)
				return (1);
		}
		else if (kill(pid_serveur, SIGUSR2) == -1)
			return (1);
		while (g_wait == 0)
		{
		}
		size++;
	}
	return (0);
}

int	send(char *line, int pid_serveur)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strjoin(line, '\n');
	while (str[i] != 0)
	{
		if (send_bin(pid_serveur, str[i]))
			return (1);
		i++;
	}
	free(str);
	return (0);
}

void	waiting(int i)
{
	(void)i;
	g_wait = 1;
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3 && ft_atoi(argv[1]) != 0)
	{
		signal(SIGUSR2, waiting);
		if (kill(ft_atoi(argv[2]), 0))
			ft_putstr_fd("Error", 1);
	}
	else if (argc != 3)
	{
		ft_putstr_fd("Error argument\n", 1);
		exit(EXIT_FAILURE);
	}
	else if (!valid_pid(argv[1]))
	{
		ft_putstr_fd("Error invalid PID caractere\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == 0)
		ft_putstr_fd("Valid PID\n", 1);
	else
		ft_putstr_fd("Error invalid PID\n", 1);
	send(argv[2], pid);
	return (0);
}
