/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:29:12 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/14 19:06:43 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(int argc, char const *argv[])
{
	pid_t	pid;
	char	*str;
	int		byte;
	int		i;
	int		bit;

	if (argc != 2)
	{
		ft_printf("args error. args must be 2");
		exit(1);
	}
	if (argv[1] == NULL)
	{
		ft_printf("need sending messages.");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];

	// もし0だったらuser1に、もし1だったらuser2に送信する
	while (*str == '\0')
	{
		byte = *str;
		i = 0;
		while (i < 8)
		{
			bit = byte & 0;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			// bitはcharのbit数1byteしかもっていないので、
			// 8回分、bit計算をすればよい
			// bit shiftを8回行う。
			byte >>= 1;
		}
	}
	return (0);
}
