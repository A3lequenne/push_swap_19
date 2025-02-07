#include "push_swap.h"

void	errors(int type, t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, lstdel);
	ft_lstclear(stack_b, lstdel);
	if (type == 1)
		ft_putstr_fd("Error\n", 1);
	if (type == 2)
		ft_putstr_fd("KO\n", 1);
	exit(EXIT_FAILURE);
}

void	do_opt(char *opt, t_list **stack, void (*f)(t_list **stack),
		t_global *global)
{
	f(stack);
	if (!global->b)
		printf("%s\n", opt);
	else
	{
		printf("\e[2J");
		ft_lstprint(global->stack_a, global->stack_b);
		printf("\n\n");
		usleep(1000000);
	}
}

void	do_push(char *opt, t_global *global, void (*f)(t_list **stack_a,
		t_list **stack_b))
{
	f(&global->stack_a, &global->stack_b);
	if (!global->b)
		printf("%s\n", opt);
	else
	{
		printf("\e[2J");
		ft_lstprint(global->stack_a, global->stack_b);
		printf("\n\n");
		usleep(1000000);
	}
}

void	freeall(t_global *global, int **tab)
{
    if (global->stack_a)
        free(global->stack_a);
    if (global->stack_b)
        free(global->stack_b);
    if (global)
        free(global);
    if (tab)
        free(tab);
    exit(EXIT_SUCCESS);
}

int	is_integers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '-' && str[i] != '+'
			&& (str[i] < '0' || str[i] > '9'))
			return (0);
	return (1);
}
