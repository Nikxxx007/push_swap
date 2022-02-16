/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:03:37 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:03:38 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*memory;
	int		i;

	i = 0;
	memory = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!memory)
		return (NULL);
	while (str[i])
	{
		memory[i] = str[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
