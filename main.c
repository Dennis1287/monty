#define _GNU_SOURCE

#include "monty.h"
#include <unistd.h>
#include <stdio.h>



int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;
    stack_t *stack = NULL;
    char *opcode;
    int value;
    char *arg;


    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
         line_number++;
        opcode = strtok(line, " \n\t\r");
        if (opcode == NULL || *opcode == '#') continue;

        if (strcmp(opcode, "push") == 0) {
            arg = strtok(NULL, " \n\t\r");
            if (arg == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            value = atoi(arg);
            push(&stack, value);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(&stack, line_number);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(&stack, line_number);
        } else if (strcmp(opcode, "add") == 0) {
            add(&stack, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(&stack, line_number);
        } else if (strcmp(opcode, "nop") == 0) {
            nop(&stack, line_number);
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
    }
    }
    fclose(file);
    if (line)
        free(line);

    return EXIT_SUCCESS;
}
