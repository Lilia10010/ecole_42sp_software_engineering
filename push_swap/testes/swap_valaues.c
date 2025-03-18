#include <stdio.h>
#include <stdlib.h>

typedef struct s_vrau
{
    int test;
    struct s_vrau *next;
} t_vrau

void swap_values(t_vrau *a, t_vrau *b)
{
    int swap = a->test;
    a->test = b->test;
    b->test = swap;
}

void crete_node(int n)
{
    
}

int main(void)
{
    t_vrau *head = crete_node(10);
    head->next = crete_node(20);
    head->next->next = (30);
    head->next->next->next = (40); 

    printf("Lista original");
    print_list(head);

    if(head && head->next)
    {
        swap_values(head, head->next);
    }

    printf("Lista trocada");
    print_list(head);

    free_list(head);

    return(0);
}