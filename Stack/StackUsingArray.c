#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter Size of Stack : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}
void Display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("Elements of Stack are : %d\n", st.s[i]);
}
void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack is overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->s[st->top--];
    }
    return x;
}
int peek(struct stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.s[st.top - index + 1];

    return x;
}
int isEmpty(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull(struct stack st)
{
    return st.top == st.size - 1;
}
int stackTop(struct stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;
}
int main()
{
    struct stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("provide positions of elements are : %d \n", peek(st, 1));
    printf("Pop  elements are : %d \n", pop(&st));
    Display(st);

    return 0;
}