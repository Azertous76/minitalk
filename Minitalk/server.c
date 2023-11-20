/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:05:19 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/20 16:45:01 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *chaine, char e)
{
	char	*final;
	int		i;

	i = 0;
	if (!e)
		return (0);
	if (!chaine)
	{
		final = malloc(sizeof(char) * 2);
		if (!final)
			return (0);
		final[0] = e;
		final[1] = '\0';
		return (final);
	}
	final = (char *)malloc(sizeof(char) * (ft_strlen(chaine) + 2));
	while (chaine[i])
	{
		final[i] = chaine[i];
		i++;
	}
	final[i] = e;
	final[i + 1] = '\0';
	return (final);
}

void	sig_handler(int signal, siginfo_t *info, void *s)
{
	static int	bits = 0;
	static int	i = 0;
	static char	*str;

	(void)s;
	if (signal == SIGUSR1)
		i |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		if (i == 0)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		if (i != 0)
			str = ft_strjoin(str, i);
		i = 0;
		bits = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	(void)argv;
	ft_printf("voici le PID : %d\n", pid);
	sig.sa_sigaction = sig_handler;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
