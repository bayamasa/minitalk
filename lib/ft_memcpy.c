#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	if (n == 0 || buf1 == buf2)
		return (buf1);
	i = 0;
	dest = (unsigned char *)buf1;
	src = (unsigned char *)buf2;
	while (n--)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (buf1);
}
