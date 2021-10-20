/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:29:12 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/20 16:48:23 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char const *argv[])
{
	pid_t		pid;
	const char	*str;
	int			byte;
	int			i;
	int			bit;

	if (argc != 3)
	{
		ft_printf("args error. args must be 3");
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
	while (*str != '\0')
	{
		byte = (int)*str;
		i = 0;
		while (i < 7)
		{
			bit = byte & MSB;
			printf("bit = %d\n", bit);
			if (bit != MSB)
				kill(pid, SIGUSR1);
			else if (bit == MSB)
				kill(pid, SIGUSR2);
			// 上から順番に送らないとシフト演算できない。
			// bitはcharのbit数1byteしかもっていないので、
			// 8回分、bit計算をすればよい
			// bit shiftを8回行う。
			byte <<= 1;
			i++;
			usleep(600);
		}
		str++;
	}
	return (0);
}
