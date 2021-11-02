#include "../../includes/push_swap.h"

int	position(t_list *head, int val)
{
	t_list	*tmp;
	int		pos;

	tmp = head;
	pos = 0;
	while (tmp->order != val)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}


int max_in(t_list *head, int pass)
{
	t_list	*tmp;
	int 	max;

	tmp = head;
	max = tmp->order;
	if (!tmp->next)
		return (max);
	tmp = tmp->next;
	while (tmp->next)
	{
		if (tmp->order > max && tmp->order != pass)
			max = tmp->order;
		tmp = tmp->next;
	}
	if (tmp->order > max)
		max = tmp->order;
	return (max);
}

int min(t_list *head)
{
	t_list	*tmp;
	int 	min;

	tmp = head;
	min = tmp->order;
	tmp = tmp->next;
	while (tmp->next)
	{
		if (tmp->order < min)
			min = tmp->order;
		tmp = tmp->next;
	}
	if (tmp->order < min)
		min = tmp->order;
	return (min);
}

int	pivot(t_list *head, int len, int max_len)
{
	t_list	*tmp;
	int		i;
	int 	j;
	int 	*arr;

	tmp = head;
	i = 0;
	j = 0;
	arr = (int *)malloc(sizeof(int *) * len);
	while (i < max_len)
	{
		while (i != tmp->order && tmp->next)
			tmp = tmp->next;
		if (i == tmp->order)
			arr[j++] = i++;
		else
			i++;
		tmp = head;
	}
	j = 0;
	while (j < (len / 2) - 1)
		j++;
	j = arr[j];

//	int k = 0;
//	while (k < len)
//		printf("%d", arr[k++]);
//	printf("\n");
//	printf("%d", j);
//	printf("\n");
	free(arr);
	return (j);
}
