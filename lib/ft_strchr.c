#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		chr;

	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (chr == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
