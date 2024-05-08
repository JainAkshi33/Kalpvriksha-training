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

void printFloat(void *f)
{
    printf(" %f", *(float *)f);
}

int main()
{
    unsigned int_size = sizeof(int);
    unsigned float_size = sizeof(float);
    int *arr;
    int numberOfElements;
    printf("Enter Size Of Integer array:-");
    scanf("%d", &numberOfElements);
    arr = (int *)malloc(numberOfElements* sizeof(int));
    printf("Enter Elements:-\n");
    for (int i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = numberOfElements - 1; i >= 0; i--)
        insert(&arr[i], int_size);
    printf("Created integer linked list is \n");
    printList(printInt);

    head = NULL;
    float *arr2;
    printf("\nEnter Size Of Float array:-");
    scanf("%d", &numberOfElements);
    arr2 = (float *)malloc(numberOfElements * sizeof(float));
    printf("Enter Elements:-\n");
    for (int i = 0; i < numberOfElements; i++)
        scanf("%f", &arr2[i]);
    for (int i = numberOfElements - 1; i >= 0; i--)
        insert(&arr2[i], float_size);
    printf("\nCreated float linked list is \n");
    printList(printFloat);

    return 0;
}
