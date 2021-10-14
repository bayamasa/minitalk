#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)buf1;
	src = (unsigned char *)buf2;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			*(dest + n) = *(src + n);
	}
	return (buf1);
}
