/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:03:27 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:03:28 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)symbol)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == symbol)
		return ((char *)(string + i));
	return (NULL);
}
