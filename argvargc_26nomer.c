#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    int* vals;
    size_t cap;
    int lenght;
} stack_t;

stack_t* init_stack(size_t cap);
void add(stack_t* stack, int val);
void pop(stack_t* stack);
void print_stack(stack_t* stack);
void back(stack_t stack);

int main(int argc, char** argv){
    stack_t *stack = init_stack(10);
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "add") == 0){
            i++;
            int value;
            if(sscanf(argv[i], "%d", &value)){
                add(stack, value);
            }else{
                printf("No value given.\n");
            }
        }else if(strcmp(argv[i], "pop") == 0){
            pop(stack);
        }else if(strcmp(argv[i], "print") == 0){
            print_stack(stack);
        }else if(strcmp(argv[i], "back") == 0){
            back(*stack);
        }else{
            printf("Unknown command\n");
        }
    }
    free(stack->vals);
    free(stack);

    return 0;
}

stack_t* init_stack(size_t cap) {
    if(!cap)
        return NULL;
    stack_t* stack = malloc(sizeof(stack_t));
    stack->cap = cap;
    stack->lenght = 0;
    stack->vals = malloc(sizeof(int) * stack->cap);

    return stack;
}

void add(stack_t* stack, int val) {
    if(stack->lenght == stack->cap) {
        stack->cap*=2;
        stack->vals = realloc(stack->vals, stack->cap);
    }

    stack->vals[stack->lenght++] = val;
}

void pop(stack_t* stack) {
    if(!stack->lenght)
        return;
    stack->lenght--;
}

void print_stack(stack_t* stack) {
    if(!stack->lenght) return;
    printf("Printing stack: ");
    for(int i = stack->lenght-1; i >= 0; i--) {
        printf("%d ", stack->vals[i]);
    }
    printf("\n");
}

void back(stack_t stack) {
    printf("Back: ");
    printf("%d\n", stack.vals[stack.lenght-1]);
}
