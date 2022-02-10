#include "../../includes/push_swap.h"

int	cmd_ex(char *line, t_list **head_a, t_list **head_b)
{
	if (!(ft_strncmp(line, "sa", 2)))
		swap_first_two_c(head_a, head_b, 'a');
	else if (!(ft_strncmp(line, "sb", 2)))
		swap_first_two_c(head_b, head_a, 'b');
	else if (!(ft_strncmp(line, "ss", 2)))
		swap_first_two_c(head_a, head_b, 's');
	else if (!(ft_strncmp(line, "pa", 2)))
		push_to_c(head_a, head_b);
	else if (!(ft_strncmp(line, "pb", 2)))
		push_to_c(head_b, head_a);
	else if (!(ft_strncmp(line, "ra", 2)))
		rotate_c(head_a, head_b, 'a');
	else if (!(ft_strncmp(line, "rb", 2)))
		rotate_c(head_b, head_a, 'b');
	else if (!(ft_strncmp(line, "rr", 2)))
		rotate_c(head_a, head_b, 'r');
	else if (!(ft_strncmp(line, "rra", 3)))
		reverse_rotate_c(head_a, head_b, 'a');
	else if (!(ft_strncmp(line, "rrb", 3)))
		reverse_rotate_c(head_b, head_a, 'b');
	else if (!(ft_strncmp(line, "rrr", 3)))
		reverse_rotate_c(head_a, head_b, 'r');
	else
		return (0);
	return (1);
}

void	print_list(t_list *head)//TODO remove
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%d - %d\n", tmp->val, tmp->order);
		tmp = tmp->next;
	}
}

void	cmd_reader(t_list **head_a, t_list **head_b)
{
	char	*line;
	int		error;

	error = 0;
	while (get_next_line(0, &line))
	{
		if (!(cmd_ex(line, head_a, head_b)))
		{
			error = 1;
			free(line);
			line = NULL;
			break ;
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;

//	print_list(*head_a);
//	printf("\n");
//	print_list(*head_b);

	if (error)
		write(1, "error\n", 6);
	else if (is_sorted(*head_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n",3);
	freeList(head_a);
	freeList(head_b);
}