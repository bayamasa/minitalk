/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:18 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/15 21:31:17 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <libc.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_sigattr
{
	int			count;
	char		bit;
}				t_sigattr;

t_sigattr	g_sigattr = {0, 0};
#endif
