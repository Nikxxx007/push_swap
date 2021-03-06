/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:11:55 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:11:56 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	nods_count(t_list **head_a)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *head_a;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len <= 1)
		return (0);
	return (1);
}

void	swap_first_two_c(t_list **head, t_list **head1, char cmd)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head;
	if (*head && nods_count(head))
	{
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		ft_lstadd_front(head, tmp2);
	}
	if (cmd == 'r')
		if (*head1)
			swap_first_two_c(head1, head, 'n');
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
	if (*head && nods_count(head))
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
	if (*head && nods_count(head))
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp_last = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(head, tmp_last);
	}
	if (cmd == 'r')
		if (*head1)
			reverse_rotate_c(head1, head, 'n');
}
