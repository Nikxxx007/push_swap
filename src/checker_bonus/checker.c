/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:11:46 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:19:16 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_dubl(int **arr, int j)
{
	int	k;

	k = j - 2;
	while (k >= 0)
	{
		if ((*arr)[k] == (*arr)[j - 1])
			er_prog_exit(arr);
		k--;
	}
	return (0);
}

int	is_valid(char **argv, int **arr)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = 0;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if (!(((*argv)[i] >= '0' && (*argv)[i] <= '9')
						|| (*argv)[i] == '-' || (*argv)[i] == '+'))
				check = 1;
			i++;
		}
		if (!check)
			(*arr)[j++] = ft_atoi(*argv, arr);
		else
			return (0);
		check_dubl(arr, j);
		argv++;
	}
	return (1);
}

void	add_order(t_list *head, int *arr)
{
	t_list	*tmp;
	int		i;

	tmp = head;
	while (tmp)
	{
		i = 0;
		while (tmp->val != arr[i])
			i++;
		tmp->order = i;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	int		*in_vals;
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	in_vals = (int *) malloc(sizeof(int) * (argc - 1));
	if (!in_vals)
		return (0);
	is_empty(argv + 1, &in_vals);
	if (argc < 2)
		er_prog_exit(&in_vals);
	if (argc == 2)
		pars_string(argv + 1, &in_vals, &argc);
	else if (!(is_valid(argv + 1, &in_vals)))
		er_prog_exit(&in_vals);
	check_arr(&in_vals);
	create_list(in_vals, &head_a, argc - 1);
	quick_sort(&in_vals, 0, argc - 1);
	add_order(head_a, in_vals);
	free(in_vals);
	cmd_reader(&head_a, &head_b);
	return (0);
}
