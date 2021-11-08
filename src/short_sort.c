#include "../includes/push_swap.h"

void	start_sort(t_list **head_a, t_list **head_b, int list_len)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < 2)
	{
		j = 0;
		if (position(*head_a, min(*head_a)) < list_len - 2)
			j = 1;
		while ((*head_a)->order != min(*head_a))
		{
			if (j)
				rotate(head_a, head_b, 'a');
			else
				reverse_rotate(head_a, head_b, 'a');
		}
		push_to(head_b, head_a, 'b');
	}
}

void	short_sort(t_list **head_a, t_list **head_b, int list_len)
{
	if (list_len > 3)
		start_sort(head_a, head_b, list_len);
	while (!is_sorted(*head_a))
	{
		if ((*head_a)->order >= max_in(*head_a, -1))
			rotate(head_a, head_b, 'a');
		else if ((*head_a)->order > (*head_a)->next->order)
			swap_first_two(head_a, head_b, 'a');
		else
			rotate(head_a, head_b, 'a');
	}
	if (list_len > 3)
	{
		push_to(head_a, head_b, 'a');
		push_to(head_a, head_b, 'a');
	}
}
