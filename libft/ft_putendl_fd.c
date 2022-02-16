/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:03:07 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:03:09 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	temp;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		temp = s[i];
		write(fd, &temp, 1);
		i++;
	}
	write(fd, "\n", 1);
}
