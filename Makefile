CC		= gcc
NAME	= push_swap
SRCS	= src/main.c \
			src/long_sort.c \
			src/short_sort.c \
			src/sort_array.c \
			src/lst_utils/new_node.c \
			src/lst_utils/commands.c \
			src/lst_utils/free_list.c \
			src/algo_utils/search.c \
			src/algo_utils/exit.c \
			src/algo_utils/is_sorted.c \
			src/parse_string/string_utils.c


OBJS		= $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc
LIBR	= ranlib
RM		= rm -f
INCL	= ./

LIBFT	= libft/libft.a

.c.o:
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)


$(NAME): 	$(OBJS)
	make bonus -C libft
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C libft
fclean:	clean
		$(RM) $(NAME)
		make fclean -C libft

re:		fclean all

.PHONY:	fclean clean re bonus
