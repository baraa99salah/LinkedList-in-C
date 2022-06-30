// Q3: (In a linear linked list, write a function that deletes the element in the middle of the list
// (free this memory location) (if the list has 100 or 101 elements, it will delete the 50th element).
// The function will take a list as a parameter and return the updated list.)
#include <stdio.h>
#include <stdlib.h>
int lenght = 0;
struct node
{
    int number;
    struct node *next;
};
typedef struct node node;

node *insertFirst()
{
    node *head, *last;
    for (int i = 0; i < 5; i++)
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
        lenght++;
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

node *deleteMiddleNode(node *head)
{
    node *last, *t;
    int halfList = lenght / 2;
    last = t = head;
    if (lenght == 1)
    {
        printf("\nthere is one node!!");
    }
    else
    {
        int counter = 1;
        while (last->next!=NULL)
        {
            last = last->next;
        }
        while (counter != halfList -1)
        {
            t = t->next;
            counter++;
        }
        if (t->next != NULL)
        {
            t->next = t->next->next;
        }
        else
        {
            printf("\nno node");
        }
    }
    return head;
}

int main()
{
    node *head;

    head = insertFirst();
    print(head);
    head = deleteMiddleNode(head);
    printf("\n");
    print(head);
}