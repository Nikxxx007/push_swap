#include "../../includes/push_swap.h"

void freeTokens(char** tokens)
{
	char **freeTokens;

	freeTokens = tokens;
	while (*freeTokens != NULL)
	{
		free(*freeTokens);
		*freeTokens = NULL;
		freeTokens++;
	}
	free(tokens);
}

void	to_arr(char **argv, int **arr, int *len)
{
	char	**strings;

	strings = ft_split(*argv, ' ');
	free(*arr);
	while (strings[(*len) - 1])
		(*len)++;
	*arr = (int *) malloc(sizeof(int *) * ((*len) - 1));
	if (!(is_valid(strings, arr)))
	{
		freeTokens(strings);
		er_prog_exit(arr);
	}
	freeTokens(strings);
}

void	pars_string(char **argv, int **arr, int *len)
{
	int	i;
	int spaces;

	i = 0;
	spaces = 0;
	while ((*argv)[i])
	{
		if ((*argv)[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces >= 1)
		to_arr(argv, arr, len);
	else if (!(is_valid(argv, arr)))
		er_prog_exit(arr);
}