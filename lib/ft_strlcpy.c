#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (*src && (size - 1))
	{
		*dest++ = *src++;
		size--;
	}
	*dest = '\0';
	return (i);
}
