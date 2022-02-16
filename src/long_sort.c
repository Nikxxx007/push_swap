/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:10:08 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:10:11 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_back(t_list **head_a, t_list **head_b, int max, t_sort **sort)
{
	int	i;

	i = 0;
	if ((*head_b)->order < max)
	{
		while ((*head_b)->order != max)
		{
			if ((*head_b)->next->order == max)
			{
				swap_first_two(head_b, head_a, 'b');
				push_to(head_a, head_b, 'a');
				i = 1;
				break ;
			}
			if ((*sort)->flags)
				rotate(head_b, head_a, 'b');
			else
				reverse_rotate(head_b, head_a, 'b');
		}
	}
	if (!i)
		push_to(head_a, head_b, 'a');
}

void	sort_util(t_list **head_a, t_list **head_b, t_sort **sort)
{
	if ((*sort)->flag_a == (*sort)->flag_b && (((*sort)->pos_a > (*sort)->pos_b
				&& (*sort)->flag_a) || ((*sort)->pos_a < (*sort)->pos_b
				&& !(*sort)->flag_a)))
	{
		push_back(head_a, head_b, (*sort)->max_a, sort);
		push_back(head_a, head_b, (*sort)->max_b, sort);
		swap_first_two(head_a, head_b, 'a');
		(*sort)->len_b--;
	}
	else
		push_back(head_a, head_b, (*sort)->max_b, sort);
}

void	add_to_a(t_list **head_a, t_list **head_b, t_sort **sort)
{
	while ((*sort)->len_b)
	{
		(*sort)->flag_a = 0;
		(*sort)->flag_b = 0;
		(*sort)->max_b = max_in(*head_b, -1);
		(*sort)->max_a = max_in(*head_b, (*sort)->max_b);
		(*sort)->pos_a = position(*head_b, (*sort)->max_b);
		if ((*sort)->pos_a < (*sort)->len_b / 2)
			(*sort)->flag_a = 1;
		(*sort)->pos_b = position(*head_b, (*sort)->max_a);
		if ((*sort)->pos_b < (*sort)->len_b / 2)
			(*sort)->flag_b = 1;
		(*sort)->flags = (*sort)->flag_a;
		sort_util(head_a, head_b, sort);
		(*sort)->len_b--;
	}
}

void	rotation(int safe, t_list **head_a, t_list **head_b, t_sort **sort)
{
	while (safe && (*sort)->len_a > 2)
	{
		if ((*head_a)->order <= (*sort)->pivot)
		{
			push_to(head_b, head_a, 'b');
			if ((*head_b)->order
				< pivot(*head_b, (*sort)->len_b, (*sort)->max_len)
				&& (*sort)->len_b > 1)
			{
				if ((*head_a)->order > (*sort)->pivot)
					rotate(head_a, head_b, 'r');
				else
					rotate(head_b, head_a, 'b');
			}
			(*sort)->len_b++;
			(*sort)->len_a--;
		}
		else
			rotate(head_a, head_b, 'a');
		safe--;
	}
}

int	long_sort(t_list **head_a, t_list **head_b, int list_len)
{
	int		safe;
	t_sort	*sort;

	sort = (t_sort *)malloc(sizeof(t_sort));
	if (!sort)
		return (0);
	sort->max_len = list_len;
	sort->len_a = list_len;
	sort->len_b = 0;
	while (sort->len_a > 2)
	{
		sort->pivot = pivot(*head_a, sort->len_a, sort->max_len);
		safe = sort->len_a;
		rotation(safe, head_a, head_b, &sort);
	}
	push_to(head_b, head_a, 'b');
	push_to(head_b, head_a, 'b');
	sort->len_b += 2;
	add_to_a(head_a, head_b, &sort);
	free(sort);
	return (1);
}
