// Q5: A singly linear list stores integer values in each node and has multiple nodes.
// Write a function using given prototype below.
// This function cuts the first node of the list and adds it to the end as last node.
// It takes beginning address of the list as a parameter and returns the updated list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
typedef struct node node;

node *insertFirst()
{
    node *head, *last;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            head = (node *)malloc(sizeof(node));
            last = head;
        }
        else
        {
            last->next = (node *)malloc(sizeof(node));
            last = last->next;
        }
        printf("enter a number : ");
        scanf("%d", &last->number);
    }
    last->next = NULL;
    return head;
}

void print(node *head)
{
    node *printer;
    printer = head;
    while (printer != NULL)
    {
        printf(" %d", printer->number);
        printer = printer->next;
    }
}

node *cutHeadaddLast(node *head)
{
    
    node *last, *temp;
    temp = last = head;
    while (last->next !=NULL)
    {
        last = last->next;
    }
    temp= head->next;
    last->next = head;
    head->next = NULL;  
    head = temp;
    last=last->next;
    return head;
}
int main()
{
    node *head;

    head = insertFirst();
    print(head);
    head = cutHeadaddLast(head);
    printf ("\n");
    print(head);
}