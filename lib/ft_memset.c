#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*dest;
	unsigned char	chr;
	size_t			i;

	i = 0;
	dest = (unsigned char *)buf;
	chr = (unsigned char)ch;
	while (i < n)
	{
		dest[i] = chr;
		i++;
	}
	return (dest);
}
