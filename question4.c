// Q4: (In a linear linked list, write a function named changeFirstAndLast
// that swaps the node at the end of the list and the node at the beginning of the list.
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

node *changeFirstAndLast(node *head)
{

    node *last, *Plast;
    Plast = last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    while (Plast->next != last)
    {
        Plast = Plast->next;
    }
    last->next = head->next;
    Plast->next = head;
    head->next = NULL;
    head = last;
    last = Plast->next;
   
    return head;
}

int main()
{
    node *head;

    head = insertFirst();
    print(head);
    head = changeFirstAndLast(head);
    printf("\n");
    print(head);
}