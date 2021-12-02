/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:14 by mhirabay          #+#    #+#             */
/*   Updated: 2021/12/02 13:17:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# define MSB 128
# define DARWIN_PID_MIN 100
# define DARWIN_PID_MAX 99999
# define INVALID_ARG_COUNT "Args error. Args counts must be just 3\n"
# define NOT_DIGIT_PID "Pid is invalid. Pid must be only digit\n"
# define INVALID_DARWIN_PID "Darwin pid in range 100 <= pid < 99999\n"
# define SIGACTION_SIGUSR1_ERR "Sigaction error by receiving SIGUSR1\n"

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "lib/ft_printf/ft_printf.h"

int	ft_perror(char *errmsg);

#endif
