/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:09:06 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/13 16:47:00 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_cbon(int signal)
{
	if (signal == SIGUSR1)
		printf("Le message est envoyer le san cho");
	else
		printf("Le message est envoyer le san cho");
}

void	ft_char_bits(int pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (str[i])
	{
		bits = 0;
		signal(SIGUSR1, ft_cbon);
		signal(SIGUSR2, ft_cbon);
		while (bits < 8)
		{
			if ((str[i] & (0x01 << bits)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	struct sigaction sa;

	if (is_digit(argv[1]) == 1)
	{
		printf("le pid est pas bon le sang ta mis des lettres");
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_char_bits(pid, argv[2]);
	}
	else
	{
		printf("rentre un truc correcte le sang sinon t fini genre ca :");
		printf(" \n ./client <pid> <ton_message>");
	}
}