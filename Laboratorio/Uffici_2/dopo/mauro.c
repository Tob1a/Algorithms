struct stack
{
    int *content;
    unsigned int max_size;
    int top;
};
struct stack *make_stack(unsigned int max_size)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack)); // vatti a vedere il padding in archittetura degli elaboratori. Ho usato la parte (struct stack *) potrei usare il typedef
    stack->max_size = max_size;
    stack->top = -1;
    stack->content = (int *)malloc(max_size * sizeof(int));
    return stack;
}

void delete(stack *stack)
{
    free(stack->content);
    free(stack);
}

int main(void)
{

    return 0;
}