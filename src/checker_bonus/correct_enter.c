/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_enter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:12:04 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:20:45 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_one(t_list **head_a, t_list **head_b)
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
	if (len == 1)
	{
		free_list(head_a);
		free_list(head_b);
		exit(0);
	}
}

void	is_empty(char **argv, int **arr)
{
	int		i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		if (!(ft_strncmp(argv[i], "", 1)))
			er_prog_exit(arr);
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
					&& j == ft_strlen(argv[i]) - 1)
				er_prog_exit(arr);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
					er_prog_exit(arr);
			j++;
		}
		i++;
	}
}
