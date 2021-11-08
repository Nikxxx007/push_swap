#include "../includes/push_swap.h"

void	swap_vals(int *val, int *val1)
{
	int	tmp;

	if (*val != *val1)
	{
		tmp = *val;
		*val = *val1;
		*val1 = tmp;
	}
}

int	partition(int **arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = (*arr)[low];
	i = low + 1;
	j = i;
	while (j < high)
	{
		if ((*arr)[j] < pivot)
		{
			swap_vals(&((*arr)[i]), &((*arr)[j]));
			i++;
		}
		j++;
	}
	swap_vals(&((*arr)[low]), &((*arr)[i - 1]));
	return (i - 1);
}

void	quick_sort(int **arr, int low, int high)
{
	int	pivot_location;

	if (low < high)
	{
		pivot_location = partition(arr, low, high);
		quick_sort(arr, low, pivot_location);
		quick_sort(arr, pivot_location + 1, high);
	}
}
