/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:18 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/22 11:47:03 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define SIGACTION_SIGUSR1_ERR "Sigaction error by receiving SIGUSR1\n"
# define SIGACTION_SIGUSR2_ERR "Sigaction error by receiving SIGUSR2\n"

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"

typedef struct s_sigattr
{
	int				count;
	unsigned char	bit;
}				t_sigattr;

t_sigattr	g_sigattr = {0, 0};

int	ft_perror(char *errmsg);

#endif
