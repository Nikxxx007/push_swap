/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:13:57 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:13:59 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_tokens(char **tokens)
{
	char	**free_tokens;

	free_tokens = tokens;
	while (*free_tokens != NULL)
	{
		free(*free_tokens);
		*free_tokens = NULL;
		free_tokens++;
	}
	free(tokens);
}

void	to_arr(char **argv, int **arr, int *len)
{
	char	**strings;

	strings = ft_split(*argv, ' ');
	free(*arr);
	while (strings[(*len) - 1])
		(*len)++;
	*arr = (int *) malloc(sizeof(int *) * ((*len) - 1));
	if (!(is_valid(strings, arr)))
	{
		free_tokens(strings);
		er_prog_exit(arr);
	}
	free_tokens(strings);
}

void	pars_string(char **argv, int **arr, int *len)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while ((*argv)[i])
	{
		if ((*argv)[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces == 0)
	{
		free(*arr);
		exit(0);
	}
	if (spaces >= 1)
		to_arr(argv, arr, len);
	else if (!(is_valid(argv, arr)))
		er_prog_exit(arr);
}
