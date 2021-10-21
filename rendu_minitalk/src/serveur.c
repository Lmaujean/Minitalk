/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 11:19:37 by lmaujean          #+#    #+#             */
/*   Updated: 2021/09/24 11:19:40 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minitalk.h"

void	define_user(int sig)
{
	static int	size = 0;
	static char	str = 0;

	if (sig == SIGUSR1)
	{
		str += 1 << size;
	}
	size++;
	if (size == 8)
	{
		ft_putchar_fd(str, 1);
		size = 0;
		str = 0;
	}
}

void	define(int sig, siginfo_t *use, void *cont)
{
	(void)cont;
	define_user(sig);
	kill(use->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig;
	char				*pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd("Mon PID est : ", 1);
	ft_putstr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	free(pid);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = define;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
