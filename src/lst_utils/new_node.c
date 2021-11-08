#include "../../includes/push_swap.h"

void	create_list(int *arr, t_list **head, int len)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < len)
	{
		tmp = new_node(arr[i], 0);
		ft_lstadd_back(head, tmp);
		i++;
	}
}

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
