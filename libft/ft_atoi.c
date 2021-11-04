#include "libft.h"
#include "../includes/push_swap.h"

int	minus_plus(const char **str, int **arr)
{
	int plus;
	int minus;

	plus = 0;
	minus = 0;
	while ((**str == '-') || (**str == '+'))
	{
		if (**str == '-')
			minus += 1;
		if (**str == '+')
			plus += 1;
		(*str)++;
	}
	if (minus >= 2 || plus >= 2)
		er_prog_exit(arr);
	else if (minus == 1)
		return (-1);
	return (1);
}

int		ft_atoi(const char *str, int **arr)
{
	unsigned int	new;
	int				minus;
	size_t			len;


	new = 0;
	minus = minus_plus(&str, arr);
	len = ft_strlen(str);
	while (*str >= '0' && *str <= '9')
	{
		new = (new * 10) + (*str - '0');
		str++;
		len--;
		if ((new > 2147483647 && minus == 1)
			|| (new > 2147483648 && minus == -1))
			er_prog_exit(arr);
	}
	if (len == 0)
		return ((int)(new * minus));
	er_prog_exit(arr);
	return (0);
}
