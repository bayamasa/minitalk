#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (new_list == NULL)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	tmp = new_list;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new_list);
}
