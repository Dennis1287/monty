#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for stack node */
typedef struct stack_s {
    int n;
    struct stack_s *next;
} stack_t;

/* Global variable for the stack */
extern stack_t *stack;

/* Function prototypes */
void push(stack_t **stack, int value);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
