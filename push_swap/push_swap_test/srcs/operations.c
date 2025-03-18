#include "push_swap.h"

// Troca os dois primeiros elementos da pilha a
void sa(t_stack **a) {
    if (!*a || !(*a)->next) return;
    int temp = (*a)->data;
    (*a)->data = (*a)->next->data;
    (*a)->next->data = temp;
	printf("sa\n");
}

// Troca os dois primeiros elementos da pilha b
void sb(t_stack **b) {
    if (!*b || !(*b)->next) return;
    int temp = (*b)->data;
    (*b)->data = (*b)->next->data;
    (*b)->next->data = temp;
	printf("sb\n");
}

// Executa sa e sb ao mesmo tempo
void ss(t_stack **a, t_stack **b) {
    sa(a);
    sb(b);
	printf("ss\n");
}

// Move o primeiro elemento da pilha b para o topo da pilha a
void pa(t_stack **a, t_stack **b) {
    if (!*b) return;
    int value = pop(b);
    push(a, value);
	printf("pa\n");
}

// Move o primeiro elemento da pilha a para o topo da pilha b
void pb(t_stack **a, t_stack **b) {
    if (!*a) return;
    int value = pop(a);
    push(b, value);
	printf("pb\n");
}

// Rotaciona a pilha a (o primeiro elemento vai para o final)
void ra(t_stack **a) {
    if (!*a || !(*a)->next) return;
    t_stack *last = *a;
    while (last->next) {
        last = last->next;
    }
    last->next = *a;
    *a = (*a)->next;
    last->next->next = NULL;
	printf("ra\n");
}

// Rotaciona a pilha b (o primeiro elemento vai para o final)
void rb(t_stack **b) {
    if (!*b || !(*b)->next) return;
    t_stack *last = *b;
    while (last->next) {
        last = last->next;
    }
    last->next = *b;
    *b = (*b)->next;
    last->next->next = NULL;
	printf("rb\n");
}

// Executa ra e rb ao mesmo tempo
void rr(t_stack **a, t_stack **b) {
    ra(a);
    rb(b);
	printf("rr\n");
}

// Rotaciona a pilha a no sentido inverso (o último elemento vai para o topo)
void rra(t_stack **a) {
    if (!*a || !(*a)->next) return;
    t_stack *second_last = NULL;
    t_stack *last = *a;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *a;
    *a = last;
	printf("rra\n");
}

// Rotaciona a pilha b no sentido inverso (o último elemento vai para o topo)
void rrb(t_stack **b) {
    if (!*b || !(*b)->next) return;
    t_stack *second_last = NULL;
    t_stack *last = *b;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *b;
    *b = last;
	printf("rrb\n");
}

// Executa rra e rrb ao mesmo tempo
void rrr(t_stack **a, t_stack **b) {
    rra(a);
    rrb(b);
	printf("rrr\n");
}