/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:00:34 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:00:35 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*memory;

	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, num * size);
	return (memory);
}
