// Q1: Adding the odd numbers to the beginning of the list
// and even numbers to the end of the list until -1 is entered from keyboard.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
typedef struct node node;
node *first, *last;
int length = 0;

node insertFirst(int num)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->number = num;
    if (length == 0)
    {
        first = last = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
}

node insertLast(int num)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->number = num;
    if (length == 0)
    {
        last = first = newNode;
        newNode->next = NULL;
    }
    else
    {
        last->next = newNode;
        newNode->next = NULL;
        last = newNode;
    }
}
void print()
{
    node *print = first;
    while (print != NULL)
    {
        printf("  %d", print->number);
        print = print->next;
    }
}
int main()
{
    printf("Enter odd or even numbers and press -1 when you wont to stop entering\n");
    int num;
    while (1)
    {
        printf("(%d) Enter a number : ", length + 1);
        scanf("%d", &num);
        if (num == -1)
            break;
        else if (num % 2 != 0)
        {
            insertFirst(num);
            length++;
        }
        else
        {
            insertLast(num);
            length++;
        }
    }
    printf ("\nthe ODD number in beginning and the EVEN number in the end of the list :\n");
    print();
    return 0;
}
