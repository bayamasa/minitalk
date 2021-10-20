/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:58:23 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/20 17:30:55 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:29:40 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/20 17:25:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == ' ' || a == '\r' || a == '\f' )
		return (1);
	return (0);
}

ssize_t	ft_atoi_err(const char *str)
{
	
}


int	ft_atoi(const char *str)
{
	size_t		i;
	long		num;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		// numに10かけて割ったものがnumとイコールじゃない場合LONGMAXのオーバーフローとなる。
		// なぜINT_MAX +1 みたいなやつかここにはいってこないのか
		// numがlongだから
		if ((num * 10 + (str[i] - '0')) / 10 != num)
			return ((int)process_flow(sign));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}

int main()
{
	char *a = "22474836490";
	printf("ft_atoi(return) = %d\n", ft_atoi(a));
}

