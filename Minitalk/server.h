/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <abailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:45:12 by abailleu          #+#    #+#             */
/*   Updated: 2023/11/20 16:42:58 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *chaine, char e);
void	sig_handler(int signal, siginfo_t *info, void *s);
int		ft_strlen(char *str);

#endif
