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

char *ft_itoa(int nbr) 
{
	if(nbr == -2147483648)
		return("-2147483648\0");
	int n = nbr;
	int len = 0;
	if (nbr <= 0)
	{
		len++;
    	}
	while (n) 
	{
		n /= 10;
		len++;
	}
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL) 
		return NULL;
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return(result);
	}
	if (nbr < 0) 
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr) 
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return result;
}

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
char *ft_strjoin(char *chaine, int e)
{
	char *final;
	int	i;

	i = 0;
	if(!e)
		return (0);
	if(!chaine)
	{
		final = malloc(sizeof(char) * 2);
		if (!final)
			return(0);
		final[0] = e;
		final[1] = '\0';
		return (final);
	}
	final = (char *)malloc(sizeof(char) * (ft_strlen(chaine) + 2));
	while(chaine[i])
	{
		final[i] = chaine[i];
		i++;
	}
	final[i] = e;
	final[i + 1] = '\0';
	return(final);
}

void	sig_handler(int signal, siginfo_t *info, void *s)
{
	int	bits;
	int	i;
    char	*str;
	(void)s;

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
		if(!i)
		{
			printf("%s", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		str = ft_strjoin(str, i);
        i = 0;
        bits = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	printf("voici le PID : %s\n", ft_itoa(getpid()));
	sig.sa_sigaction = sig_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}