#include "monty.h"

void push(stack_t **stack, int value) {
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->next = *stack;
    *stack = new_node;
}

void pall(stack_t **stack) {
    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

void nop(stack_t **stack, unsigned int line_number) {
    (void) stack;
    (void) line_number;
}

