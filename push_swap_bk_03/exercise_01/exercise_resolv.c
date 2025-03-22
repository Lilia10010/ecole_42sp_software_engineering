//Solução 2:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

//Solução 3
#include <stdio.h>

int main() {
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    int wordCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n') {
            wordCount++;
        }
    }
    fclose(file);
    printf("Word count: %d\n", wordCount);
    return 0;
}

//Algoritmos de Ordenação
//    Solução 1:

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Solução 2
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

//Solução 3

struct Node {
    int data;
    struct Node* next;
};

void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);
}

struct Node* sortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}



//Estruturas de Dados
//   Solução 1:
#define MAX 100

struct Stack {
    int top;
    int items[MAX];
};

void push(struct Stack* s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = x;
    }
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

//Solução 2
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

//Solução 3
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))