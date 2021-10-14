#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	chr = (char)c;
	if (chr == '\0')
		return (ft_strchr(s, '\0'));
	i = ft_strlen(s);
	while (i--)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
	}
	return (NULL);
}
