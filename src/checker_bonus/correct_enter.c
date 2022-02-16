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

void	check_arr(int **arr)
{
	int	len;

	len = 0;
	while ((*arr)[len])
		len++;
	if (len == 1)
	{
		free(*arr);
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
