#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len--)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && haystack[i + j] != '\0' )
			{
				if (needle[j + 1] == '\0')
				{
					if (len < j)
						return (NULL);
					return ((char *)&haystack[i]);
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
