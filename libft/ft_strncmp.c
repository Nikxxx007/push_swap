/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:04:02 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:04:03 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && ((unsigned char)string1[i] != '\0'
			|| (unsigned char)string2[i] != '\0'))
	{
		if ((unsigned char)string1[i]
			!= (unsigned char)string2[i])
			return ((int)((unsigned char)string1[i]
				- (unsigned char)string2[i]));
		i++;
	}
	return (0);
}
