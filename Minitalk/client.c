/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:09:06 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/20 16:46:27 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
		ft_printf("Le message est envoyer le san cho\n");
}

void	ft_dernier_cara(int bits, int pid)
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
	int					pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		if (is_digit(argv[1]) == 1)
			ft_printf("le pid est pas bon le sang ta mis des lettres\n");
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
		ft_printf("rentre un truc correcte le sang sinon t fini genre ca :");
		ft_printf(" \n ./client <pid> <ton_message>\n");
	}
}
