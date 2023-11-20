/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:09:06 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/18 19:22:39 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	mult;

	i = 0;
	nb = 0;
	mult = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
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

void	ft_cbon(int signal, siginfo_t *info, void *s)
{
	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		printf("Le message est envoyer le san cho");
}

void ft_dernier_cara(int bits, int pid)
{
	while (bits < 8)
	{
		if (('\0' & (0x01 << bits)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		usleep(5000);
	}
}
void	ft_char_bits(int pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (str[i])
	{
		bits = 0;
		while (bits < 8)
		{
			if ((str[i] & (0x01 << bits)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			usleep(5000);
		}
		i++;
	}
	bits = 0;
	ft_dernier_cara(bits, pid);
}

int	main(int argc, char **argv)
{
	int pid;
	struct sigaction sa;

	if (argc == 3)
	{
		if (is_digit(argv[1]) == 1)
		{
			printf("le pid est pas bon le sang ta mis des lettres");
		}
		pid = ft_atoi(argv[1]);
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = ft_cbon;
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