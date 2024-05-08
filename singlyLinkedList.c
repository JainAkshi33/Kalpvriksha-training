#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int val)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void insertionAtEnd(int val)
{
    struct Node *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        tail->next = new_node;
    }
    tail = new_node;
}

void insertionAtStart(int val)
{
    struct Node *new_node = createNode(val);
    if (tail == NULL)
    {
        tail = new_node;
    }

    new_node->next = head;
    head = new_node;
}

void insertionAfterValue(int val1, int val)
{
    struct Node *new_node = createNode(val);
    struct Node *temp = head;
    while (temp->data != val1)
    {
        temp = temp->next;
    }
    if (temp->data == val1)
    {
        new_node->next = temp->next;
        temp->next = new_node;
    }
    else
    {
        printf("value not found!\n");
    }
}

void inserationAtPosition(int position, int val)
{
    struct Node *new_node = createNode(val);
    struct Node *temp = head;
    int count = 0;
    if (position == 0)
    {
        insertionAtStart(val);
        return;
    }
    while (count != (position - 1))
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        else
        {
            printf("position not available\n");
            return;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deletionFromStart()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("No element in linked list\n");
        return;
    }
    if (head->next != NULL)
        head = head->next;
    else
        head = NULL;
    free(temp);
}

void deletionFromEnd()
{
    struct Node *prev = NULL;
    struct Node *end = head;
    if (head == NULL)
    {
        printf("No element in linked list\n");
        return;
    }
    while (end->next)
    {
        prev = end;
        end = end->next;
    }
    if (prev == NULL)
    {
        head = NULL;
    }
    else
        prev->next = NULL;
    tail = prev;
    free(end);
}

void deleteFromPosition(int position)
{
    if (head == NULL)
    {
        printf("No element in linked list\n");
        return;
    }
    struct Node *prev = head;
    struct Node *temp = NULL;
    for (int i = 0; i < position - 1; i++)
    {
        if (prev->next != NULL)
            prev = prev->next;
        else
            printf("Position not valid\n");
    }
    temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

void show()
{
    if(head==NULL){
        printf("The list is empty");
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int flag = 1;
    int choice;
    int value, position, value1;
    do
    {

        printf("\n1.Insert at start\n");
        printf("2.Insert at end\n");
        printf("3.Insert after an element\n");
        printf("4.Insert at particular position\n");
        printf("5.Delete element from start\n");
        printf("6.Delete element from end\n");
        printf("7.Delete from particular position\n");
        printf("8.Show complete linked list\n");
        printf("9.Exit\n");
        printf("What do you want to do : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value you want to insert: ");
            scanf("%d", &value);
            insertionAtStart(value);
            break;
        }

        case 2:
        {
            printf("Enter the value you want to insert: ");
            scanf("%d", &value);
            insertionAtEnd(value);
            break;
        }

        case 3:
        {
            printf("Enter the value after which you want to insert: ");
            scanf("%d", &value1);
            printf("Enter the value you want to insert: ");
            scanf("%d", &value);
            insertionAfterValue(value1, value);
            break;
        }

        case 4:
        {
            printf("Enter the position at which you want to insert: ");
            scanf("%d", &position);
            printf("Enter the value you want to insert: ");
            scanf("%d", &value);
            inserationAtPosition(position, value);
            break;
        }

        case 5:
            deletionFromStart();
            break;

        case 6:
            deletionFromEnd();
            break;

        case 7:
        {
            printf("Enter the position from which you want to delete: ");
            scanf("%d", &position);
            deleteFromPosition(position);
            break;
        }

        case 8:
            show();
            break;

        case 9:
            flag = 0;
            break;
        default:
            break;
        }
    } while (flag == 1);
    return 0;
}
