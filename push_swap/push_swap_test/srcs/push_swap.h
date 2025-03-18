#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

// Funções básicas
t_stack *create_node(int value);
void push(t_stack **stack, int value);
int pop(t_stack **stack);
void print_stack(t_stack *stack, char *name);

// Operações
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

// Merge Sort
void merge_sort(t_stack **a, t_stack **b, int size);


#endif