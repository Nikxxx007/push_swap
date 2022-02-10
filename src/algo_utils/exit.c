#include "../../includes/push_swap.h"

void	er_prog_exit(int **arr)
{
	write(2, "Incorrect in values\n", 20);
	free(*arr);
	exit(1);
}
