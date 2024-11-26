#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int Data;
    struct Node *next;
} *first = NULL;

void CreateNode(int A[], int n)
{
    struct Node *temp, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->Data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->Data = A[i];
        temp->prev = last;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void DisplayElement(struct Node *p)
{
    while (p)
    {
        printf("Elements are : %d ", p->Data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    CreateNode(A, 5);
    printf("Length is : %d\n", Length(first));
    DisplayElement(first);
    return 0;
}