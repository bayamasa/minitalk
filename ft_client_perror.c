/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_perror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:52:41 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/20 22:50:09 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_client_perror(char *errmsg)
{
	ft_putstr_fd(errmsg, STDERR_FILENO);
	return (-1);
}
