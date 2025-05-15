linked_list.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
int data;
struct Node\* next;
} Node;

void push(Node\*_ head, int data);
Node_ reverse_list(Node* head);
void print_list(Node* head);
void free_list(Node\* head);

#endif

linked_list.c
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void push(Node\*_ head, int data) {
Node_ new_node = (Node*)malloc(sizeof(Node));
new_node->data = data;
new_node->next = *head;
\*head = new_node;
}

Node* reverse_list(Node* head) {
Node* prev = NULL;
Node* current = head;
Node\* next = NULL;
while (current != NULL) {
next = current->next;
current->next = prev;
prev = current;
current = next;
}
return prev;
}

void print_list(Node* head) {
Node* temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

void free_list(Node* head) {
Node* temp;
while (head != NULL) {
temp = head;
head = head->next;
free(temp);
}
}

---

file_ultis.h
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

int count_words_in_file(const char\* filename);

#endif

file_ultis.c
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int count_words_in_file(const char* filename) {
FILE* file = fopen(filename, "r");
if (file == NULL) {
perror("Erro ao abrir o arquivo");
return -1;
}

    int word_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            word_count++;
        }
    }

    fclose(file);
    return word_count + 1; // Adiciona 1 para contar a última palavra

}

compilar
make # Compila o projeto
./main # Executa o programa
make clean # Limpa os arquivos objeto e o executável
