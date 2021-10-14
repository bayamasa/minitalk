#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	size_t		len;
	char		*dest;

	if (src == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
