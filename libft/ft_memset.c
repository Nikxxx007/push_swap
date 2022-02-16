/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:02:57 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:02:58 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)destination;
	i = 0;
	while (i < n)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return (destination);
}
