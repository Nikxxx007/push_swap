#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

# include "../libft/libft.h"

typedef struct	s_sort
{
	int 		max_len;
	int 		flag_a;
	int 		flag_b;
	int 		max_a;
	int 		max_b;
	int 		len_a;
	int 		len_b;
	int 		pos_a;
	int 		pos_b;
	int 		pivot;
	int 		flags;
}				t_sort;

t_list	*new_node(int value, int order);
void	swap_first_two(t_list **head, t_list **head1, char cmd);
void 	push_to(t_list **head1, t_list **head, char cmd);
void 	rotate(t_list **head, t_list **head1, char cmd);
void	reverse_rotate(t_list **head, t_list **head1, char cmd);

void	er_prog_exit(int **arr);

void	quick_sort(int **arr, int low, int high);

void	short_sort(t_list **head_a, t_list **head_b, int list_len);

int long_sort(t_list **head_a, t_list **head_b, int list_len);

int		position(t_list *head, int val);
int		max_in(t_list *head, int pass);
int		min(t_list *head);
int		pivot(t_list *head, int len, int max_len);

int	is_sorted(t_list *head);

void print_list(t_list *head);

#endif
