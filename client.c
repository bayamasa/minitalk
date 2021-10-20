/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:29:12 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/20 22:14:58 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	check_args(int argc, char const *argv[], pid_t *pid)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("args error. args must be 3\n", STDERR_FILENO);
		return (-1);
	}
	if (argv[1] == NULL)
	{
		ft_putstr_fd("need sending message\n", STDERR_FILENO);
		exit(0);
	}
	len = ft_strlen(argv[1]);
	while (i < len)
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd("args error. pid must be digit\n", STDERR_FILENO);
			return (-1);
		}
		i++;
	}
	*pid = ft_atoi(argv[1]);
	if (*pid < DARWIN_PID_MIN && *pid >= DARWIN_PID_MAX)
	{
		ft_putstr_fd("args error. pid ge 100, lt 99999\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	pid_t		pid;
	const char	*str;
	int			byte;
	int			i;
	int			bit;
	int			res;

	res = check_args(argc, argv, &pid);
	if (res == -1)
		exit(1);
	str = argv[2];
	while (*str != '\0')
	{
		byte = (int)*str;
		i = 0;
		while (i < 7)
		{
			bit = byte & MSB;
			if (bit != MSB)
				kill(pid, SIGUSR1);
			else if (bit == MSB)
				kill(pid, SIGUSR2);
			byte <<= 1;
			i++;
			usleep(600);
		}
		str++;
	}
	return (0);
}
