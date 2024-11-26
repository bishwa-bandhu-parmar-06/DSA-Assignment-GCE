#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Head = NULL;

void CreateNode(int A[], int n)
{
    struct Node *temp, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

int DeleteNode(int pos)
{
    struct Node *p, *q;
    int x;

    if (pos == 1)
    {
        p = Head;
        while (p->next != Head)
        {
            p = p->next;
        }
        x = Head->data;
        if (p == Head)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        p = Head;
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

void DisplayElement(struct Node *p)
{
    if (Head != NULL)
    {
        do
        {
            printf("Element of Circular Linked List: %d\n", p->data);
            p = p->next;
        } while (p != Head);
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    CreateNode(A, 5);
    printf("Nodes Are Created.\n");
    DeleteNode(2);
    printf("Now, Displaying the Elements of Circular Linked List.\n");
    DisplayElement(Head);
    return 0;
}
