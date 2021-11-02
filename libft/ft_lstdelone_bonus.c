#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	del(lst->val);
	free(lst);
}
