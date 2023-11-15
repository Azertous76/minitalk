/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:05:19 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/13 20:49:21 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}
char ft_strjoin(char *chaine, int e)
{
	char *final;
	int	i;

	i = 0;
	final = (char *)malloc(sizeof(char) * (ft_strlen(chaine) + 2));
	if(!chaine)
	{
		return (0);
	}
	if(!e)
	{
		return (0);
	}
	if(!chaine)
	{
		final[i] = e;
		i++;
		final[i] = '\0'; 
	}
	while(chaine[i])
	{
		final[i] = chaine[i];
		i++;
	}
	final[i] = e;
	i++;
	final[i] = '\0';
	return(final);
}

void	sig_handler(int signal, siginfo_t *info, void *s)
{
	int	bits;
	int	i;
    char	*str;

	bits = 0;
	i = 0;
    str = NULL;
	if (signal == SIGUSR1)
	{
		i |= (0x01 << bits);
	}
	bits++;
	if (bits == 8)
	{
		str = ft_strjoin(*str, i);
        i = 0;
        bits = 0;
	}
	printf("%s", str);
	free(str);
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	printf("voici le PID : %d\n", itoa(getpid()));
	sig.sa_handle = sig_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}