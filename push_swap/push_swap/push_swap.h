#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
#include <unistd.h>

typedef struct s_node 
{
	int		data;
	int		index;
	int		move_cost; //armazena o valor do "custo da movimentação"
	bool	above_median;
	bool	cheapest;	//mais barato
	struct	s_node *target_node; // no alvo
	struct	s_node *next;
	struct	s_node *prev;
} t_node;

void	free_args(char **args);
void	free_stack(t_node **stack);
void	free_errors(t_node **a);
int		error_syntax(char *str);
int		error_duplicate(t_node *a, int n);

//operaions
void	push(t_node **dst, t_node **src, const char *operation);
void	sa(t_node	**a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	sort_stack_with_aux(t_node **a, t_node **b);

char	**ft_split(char *str,  char delimiter);

void	init_stack_a(t_node **a, char **args);
t_node	*get_cheapest(t_node *stack);
void	prep_for_push(t_node **stack, t_node *top_node, char stack_name);

bool	is_sorted_ascending(t_node *stack);
int		stack_len(t_node *stack);
t_node	*find_last(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);

void	current_index(t_node *stack);
void	set_cheapest(t_node *stack);
void	init_nodes_a(t_node *a, t_node *b);

void	init_nodes_b(t_node *a, t_node *b);

void	sort_three(t_node **a);



#endif