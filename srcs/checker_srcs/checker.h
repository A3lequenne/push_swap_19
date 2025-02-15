#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_global
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_global;

// Checks errors args
int			is_same(t_list *lst, int val);
int			is_integers(char *str);
int			free_table(char **str, int j);
int			check_arguments(char **av, t_list **stack_a);
int			countnum(char **av);
void		ft_lstprint(t_list *lst, t_list *lst2);

// Operators
//void		do_opt(char *opt, t_list **stack_a, void (*f)(t_list **stack_a));
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		rb(t_list **stack_b);
void		ra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rra(t_list **stack_a);
void		rr_rrr(t_list **stack_a, t_list **stack_b, int type);

// Utils
int			ft_verif(t_list *lst, t_list *lst2);
void		ft_lstprint(t_list *lst, t_list *lst2);
void		errors(int type, t_list **stack_a, t_list **stack_b);
void		lstdel(void *data);
int			ft_atoi_modif(const char *str, int *max);

#endif