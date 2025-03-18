
#include "linked_list.h"

int main(void)
{
    Node* head = NULL;
    int i = 0;
    while(i <= 9)
    {
        push(&head, i);
        ++i;
    }
    printf("Lista originall: ");
    print_list(head);
    head = reverse_list(head);
    printf("Lista invertida: ");
    print_list(head);
    free_list(head);

 
    return (0);
}