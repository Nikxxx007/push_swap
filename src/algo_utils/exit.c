#include "../../includes/push_swap.h"

void	er_prog_exit(int **arr)
{
	write(2, "Incorrect in values", 19);
	free(*arr);
	exit(1);
}
