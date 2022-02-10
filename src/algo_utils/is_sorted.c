#include "../../includes/push_swap.h"

int	is_sorted(t_list *head)
{
	t_list	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->order != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
