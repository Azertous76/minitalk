/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:16 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/20 16:19:51 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		is_digit(char *str);
void	ft_cbon(int signal, siginfo_t *info, void *s);
void	ft_dernier_cara(int bits, int pid);
void	ft_char_bits(int pid, char *str);

#endif
