#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		return (ft_strdup(""));
	if (size < len)
		len = size;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
