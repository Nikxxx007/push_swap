/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:02:06 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:02:06 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*elem_temp;

	while (*lst)
	{
		del((*lst)->val);
		elem_temp = *lst;
		*lst = elem_temp->next;
		free(elem_temp);
	}
	lst[0] = NULL;
}
