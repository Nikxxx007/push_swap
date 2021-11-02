#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->val);
		lst = lst->next;
	}
}
