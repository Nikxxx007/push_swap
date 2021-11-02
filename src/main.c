#include "../includes/push_swap.h"

void er_prog_exit(int **arr)
{
	printf("Incorrect in values");
	free(*arr);
	exit(1);
}

void print_list(t_list *head)
{
	t_list *tmp;
	int i = 0;

	tmp = head;
	while (tmp)
	{
		printf("%d %d \n", tmp->val, tmp->order);
		i++;
		tmp = tmp->next;
	}
}

int	check_dubl(int **arr, int j)
{
	int k;

	k = j - 2;
	while (k >= 0)
	{
		if ((*arr)[k] == (*arr)[j - 1])
			er_prog_exit(arr);
		k--;
	}
	return (0);
}

int	is_valid(char **argv, int **arr)
{
	int	i;
	int j;
	int	check;

	check = 0;
	j = 0;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if (!(((*argv)[i] >= '0' && (*argv)[i] <= '9') || (*argv)[i] == '-'))
				check = 1;
			i++;
		}
		if (!check)
			(*arr)[j++] = ft_atoi(*argv, arr);
		else
			return (0);
		check_dubl(arr, j);
		argv++;
	}
	return (1);
}

void	create_list(int *arr, t_list **head)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (arr[i])
	{
		tmp = new_node(arr[i], 0);
		ft_lstadd_back(head, tmp);
		i++;
	}
}

void	add_order(t_list *head, int *arr)
{
	t_list *tmp;
	int i;

	tmp = head;
	while (tmp)
	{
		i = 0;
		while (tmp->val != arr[i])
			i++;
		tmp->order = i;
		tmp = tmp->next;
	}
}

int	is_sorted(t_list *head)
{
	t_list	*tmp;
	int		i;

	tmp = head;
	i = tmp->order;
	while (tmp)
	{
		if (tmp->order != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void list_sort(int list_len, t_list **head_a, t_list **head_b)
{
	if (!(is_sorted(*head_a)))
	{
		if (list_len > 8)
			long_sort(head_a, head_b, list_len);
		else
			short_sort(head_a, head_b, list_len);
	}
}

void	freeList(t_list **head)
{
	t_list	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

int main(int argc, char **argv)
{
	int i;
	int *in_vals;
	t_list *head_a = NULL;
	t_list *head_b = NULL;

	i = 0;
	in_vals = (int *) malloc(sizeof(int *) * (argc - 1));
	if (!in_vals)
		return (0);
	if (argc < 2)
		er_prog_exit(&in_vals);
	if (!(is_valid(argv + 1, &in_vals)))
		er_prog_exit(&in_vals);
	create_list(in_vals, &head_a);
	quick_sort(&in_vals, 0, argc - 1);
	add_order(head_a, in_vals);
	free(in_vals);
	list_sort(argc - 1, &head_a, &head_b);
	freeList(&head_a);
	return 0;
}