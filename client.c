/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:29:12 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/22 20:10:34 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	check_args(int argc, char const *argv[], pid_t *pid)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (argc != 3)
		return (ft_perror(INVALID_ARG_COUNT));
	len = ft_strlen(argv[1]);
	while (i < len)
	{
		if (!ft_isdigit(argv[1][i]))
			return (ft_perror(NOT_DIGIT_PID));
		i++;
	}
	*pid = ft_atoi(argv[1]);
	if (*pid < DARWIN_PID_MIN && *pid >= DARWIN_PID_MAX)
		return (ft_perror(INVALID_DARWIN_PID));
	return (0);
}

void	send_msg(unsigned char byte, pid_t pid)
{
	unsigned char	bit;
	int				i;

	i = 0;
	while (i < 8)
	{
		bit = byte & MSB;
		if (bit != MSB)
			kill(pid, SIGUSR1);
		else if (bit == MSB)
			kill(pid, SIGUSR2);
		byte <<= 1;
		i++;
		usleep(250);
	}
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;
	size_t	i;

	if (check_args(argc, argv, &pid) == -1)
		exit(1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_msg((unsigned char)argv[2][i], pid);
		i++;
		usleep(2000);
	}
	return (0);
}
