#include "../../includes/push_swap.h"

void	swap_first_two_c(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head;
	if (*head)
	{
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		ft_lstadd_front(head, tmp2);
	}
	if (cmd == 'r')
		if (*head1)
			rotate_c(head1, head, 'n');
}

void	push_to_c(t_list **head1, t_list **head)
{
	t_list	*tmp;

	if (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_lstadd_front(head1, tmp);
	}
}

void	rotate_c(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp;

	tmp = *head;
	if (*head)
	{
		*head = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(head, tmp);
	}
	if (cmd == 'r')
		if (*head1)
			rotate_c(head1, head, 'n');
}

void	reverse_rotate_c(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp;
	t_list	*tmp_last;

	tmp = *head;
	if (*head)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp_last = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(head, tmp_last);
	}
	if (cmd == 'r')
		if (*head1)
			rotate_c(head1, head, 'n');
}