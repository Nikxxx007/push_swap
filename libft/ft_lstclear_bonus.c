#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*elem_temp;

	while (*lst)
	{
		del((*lst)->val);
		elem_temp = *lst;
		*lst = elem_temp->next;
		free(elem_temp);
	}
	lst[0] = NULL;
}
