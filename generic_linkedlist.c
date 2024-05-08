#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    void *data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(void *new_data, size_t data_size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = malloc(data_size);
    new_node->next = (head);
    memcpy(new_node->data, new_data, data_size);
    head = new_node;
}

void printList(void (*fptr)(void *))
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        (*fptr)(temp->data);
        temp = temp->next;
    }
}

void printInt(void *n)
{
    printf(" %d", *(int *)n);
}

void printChar(void *c)
{
    printf(" %c", *(char *)c);
}

void printFloat(void *f)
{
    printf(" %f", *(float *)f);
}

void intList()
{
    unsigned int_size = sizeof(int);
    int *arr;
    int numberOfElements;
    printf("Enter Size Of Integer array:-");
    scanf("%d", &numberOfElements);
    arr = (int *)malloc(numberOfElements * sizeof(int));
    printf("Enter Elements:-\n");
    for (int i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = numberOfElements - 1; i >= 0; i--)
        insert(&arr[i], int_size);
    printf("Created integer linked list is \n");
    printList(printInt);
}

void floatList()
{
    unsigned float_size = sizeof(float);
    int numberOfElements;
    float *arr2;
    printf("Enter Size Of Float array:-");
    scanf("%d", &numberOfElements);
    arr2 = (float *)malloc(numberOfElements * sizeof(float));
    printf("Enter Elements:-\n");
    for (int i = 0; i < numberOfElements; i++)
        scanf("%f", &arr2[i]);
    for (int i = numberOfElements - 1; i >= 0; i--)
        insert(&arr2[i], float_size);
    printf("\nCreated float linked list is \n");
    printList(printFloat);
}

void charList()
{
    unsigned char_size = sizeof(char);
    int numberOfElements;
    char *arr3;
    printf("\nEnter Size Of char array:-");
    scanf("%d", &numberOfElements);
    arr3 = (char *)malloc(numberOfElements * sizeof(char));
    printf("Enter Elements:-\n");
    for (int i = 0; i < numberOfElements; i++)
        scanf(" %c", &arr3[i]);
    for (int i = numberOfElements - 1; i >= 0; i--)
        insert(&arr3[i], char_size);
    printf("\nCreated char linked list is \n");
    printList(printChar);
}

int main()
{
    int choice;
    printf("1.Integer linked list\n");
    printf("2.Float linked list\n");
    printf("3.Character linked list\n");
    printf("Enter the type of linkedlist you want(1/2/3):- ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        intList();
        break;

    case 2:
        floatList();
        break;

    case 3:
        charList();
        break;

    default:
        break;
    }

    return 0;
}
