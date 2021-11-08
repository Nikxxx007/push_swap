#include "../../includes/push_swap.h"

void	swap_first_two(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	ft_lstadd_front(head, tmp2);
	if (cmd == 'a')
		write(1, "sa\n", 3);
	if (cmd == 'b')
		write(1, "sb\n", 3);
	if (cmd == 'r')
	{
		write(1, "ss\n", 3);
		rotate(head1, head, 'n');
	}
}

void	push_to(t_list **head1, t_list **head, char cmd)
{
	t_list	*tmp;

	tmp = *head;
	*head = tmp->next;
	ft_lstadd_front(head1, tmp);
	if (cmd == 'a')
		write(1, "pa\n", 3);
	if (cmd == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp;

	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(head, tmp);
	if (cmd == 'a')
		write(1, "ra\n", 3);
	if (cmd == 'b')
		write(1, "rb\n", 3);
	if (cmd == 'r')
	{
		write(1, "rr\n", 3);
		rotate(head1, head, 'n');
	}
}

void	reverse_rotate(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp;
	t_list	*tmp_last;

	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp_last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(head, tmp_last);
	if (cmd == 'a')
		write(1, "rra\n", 4);
	if (cmd == 'b')
		write(1, "rrb\n", 4);
	if (cmd == 'r')
	{
		write(1, "rrr\n", 4);
		rotate(head1, head, 'n');
	}
}
