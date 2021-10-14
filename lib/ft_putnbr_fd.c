#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	num;

	num = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar_fd('0' + num, fd);
	}
}
