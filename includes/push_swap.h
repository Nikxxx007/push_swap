/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:50:05 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 14:50:28 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

# include "../libft/libft.h"

# define BUFF_SIZE 8

typedef struct s_sort
{
	int			max_len;
	int			flag_a;
	int			flag_b;
	int			max_a;
	int			max_b;
	int			len_a;
	int			len_b;
	int			pos_a;
	int			pos_b;
	int			pivot;
	int			flags;
}				t_sort;

t_list	*new_node(int value, int order);
void	swap_first_two(t_list **head, t_list **head1, char cmd);
void	push_to(t_list **head1, t_list **head, char cmd);
void	rotate(t_list **head, t_list **head1, char cmd);
void	reverse_rotate(t_list **head, t_list **head1, char cmd);

void	er_prog_exit(int **arr);

void	quick_sort(int **arr, int low, int high);

void	short_sort(t_list **head_a, t_list **head_b, int list_len);

int		long_sort(t_list **head_a, t_list **head_b, int list_len);

int		position(t_list *head, int val);
int		max_in(t_list *head, int pass);
int		min(t_list *head);
int		pivot(t_list *head, int len, int max_len);

int		is_sorted(t_list *head);

void	free_list(t_list **head);

int		is_valid(char **argv, int **arr);

t_list	*new_node(int value, int order);
void	create_list(int *arr, t_list **head, int len);

void	pars_string(char **argv, int **arr, int *len);

void	cmd_reader(t_list **head_a, t_list **head_b);
int		get_next_line(int const fd, char **line);
void	check_arr(int **arr);
void	is_empty(char **argv, int **arr);

void	swap_first_two_c(t_list **head, t_list **head1, char cmd);
void	push_to_c(t_list **head1, t_list **head);
void	rotate_c(t_list **head, t_list **head1, char cmd);
void	reverse_rotate_c(t_list **head, t_list **head1, char cmd);

void	ft_free(char **str);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
int		final(t_list *head);
#endif
