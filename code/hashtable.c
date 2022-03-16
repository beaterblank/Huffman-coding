

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 256

struct node
{
    unsigned short data;
    struct node *next;
};

struct node *chain[SIZE];

void init()
{
    int i;
    for(i = 0; i < SIZE; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % SIZE;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < SIZE; i++)
    {
        struct node *temp = chain[i];
        if (temp == NULL)
        {
            continue;
        }
        else
        {
            printf("chain[%d]-->",i);
            while(temp)
            {
                printf("%d -->",temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

int count(char a)
{
    int i = (int)a;
    struct node *temp = chain[i];
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    //init array of list to NULL
    init();

    insert('a');
    insert('a');
    insert('b');
    insert('c');
    insert('d');
    insert('e');
    insert('f');
    printf("%d\n",count('a'));
    printf("%d\n",count('f'));
    printf("%d\n",count('z'));

    print();

    return 0;
}