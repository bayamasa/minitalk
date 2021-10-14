#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			i;
	t_list		*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
