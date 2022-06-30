// Q7: Write a function that takes two parameters head (list name) and age (given student age).
// The function deletes node (free this memory location) by finding the second node with the given age value in the list.
// Write the required function using the prototype given below.

#include <stdio.h>
#include <stdlib.h>
int lenght = 0;
struct node
{
    int age;
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
        printf("enter a age : ");
        scanf("%d", &last->age);
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
        printf(" %d", printer->age);
        printer = printer->next;
    }
}

node *deleteNode(node *head, int age)
{
    node *p, *q;
    p = head;
    if (p->age == age) // delete at the beginning
    {
        head = p->next;
        free(p);
    }
    else
    {
        while (p->next != NULL && p->age != age)
        {
            q = p;
            p = p->next;
        }
        if (p->age == age)
        {
            q->next = p->next;
            free(p);
        }
        else if (p->next == NULL)
        {
            printf("\nno node");
        }
    }
    return head;
}

int main()
{
    node *head;
    int age = 0;
    head = insertFirst();
    print(head);
    printf("\nenter tha age that will be deleted\n");
    scanf("%d", &age);
    head = deleteNode(head, age);
    printf("\n");
    print(head);
}