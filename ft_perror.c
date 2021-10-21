/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:52:41 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/21 16:45:44 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf/libft/libft.h"

int	ft_perror(char *errmsg)
{
	ft_putstr_fd(errmsg, STDERR_FILENO);
	return (-1);
}
