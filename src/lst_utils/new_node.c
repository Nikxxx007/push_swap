#include "../../includes/push_swap.h"

t_list	*new_node(int value, int order)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = value;
	new->next = NULL;
	new->order = order;
	new->flag = 0;
	return (new);
}
