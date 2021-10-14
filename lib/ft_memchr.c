#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)buf;
	while (i < n)
	{
		if (str[i] == (unsigned char)ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
