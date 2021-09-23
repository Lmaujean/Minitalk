#include "../header/Minitalk.h"

static int g_wait = 0;

int	valid_pid(char *pid_serveur)
{
	int i;
	
	i = 0;
	while (pid_serveur[i])
	{
		if (ft_isdigit(pid_serveur[i]))
			i++;
		else
			return (0);
	}
	return(1);
}

int	send_bin(int pid_serveur, char str)
{
	int size;

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

int main(int argc, char **argv)
{
    int pid;

    if (argc == 3 && ft_atoi(argv[1]) != 0)
	{
		signal(SIGUSR2, waiting);
		if (kill(ft_atoi(argv[2]), 0))
			ft_putstr_fd("Error", 1);	
	}
	else if (argc != 3)
    {
        printf("Error not enough argument\n");
        exit(EXIT_FAILURE);
    }
	else if (!valid_pid(argv[1]))
	{
		printf("Error invalid PID caractere\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == 0)
		printf("Valid PID\n");
	else
		printf("Error invalid PID\n");
	send(argv[2], pid);
    return (0);
}