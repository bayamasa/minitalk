#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)buf1;
	str2 = (unsigned char *)buf2;
	while (n--)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (0);
}
