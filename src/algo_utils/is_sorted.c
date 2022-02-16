/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:11:21 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:11:22 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	final(t_list *head)
{
	t_list	*tmp;
	int		i;

	tmp = head;
	i = 0;
	if (!head)
		return (0);
	while (tmp)
	{
		if (tmp->order != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted(t_list *head)
{
	t_list	*tmp;
	int		i;

	tmp = head;
	i = tmp->order;
	if (!head)
		return (0);
	while (tmp)
	{
		if (tmp->order != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
