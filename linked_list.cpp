#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    struct node *prev;
    int roll_no;
    char name[20];
    int year;
    char section;
    char from[20];
    struct node *next;
} *start = NULL;

typedef struct node node;

node *create()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    cout << "Enter roll no\n";
    cin >> newnode->roll_no;
    cout << "Enter Name\n";
    gets(newnode->name);
    cout << "Enter year\n";
    cin >> newnode->year;
    cout << "Enter section\n";
    cin >> newnode->section;
    cout << "Enter which state you came from\n";
    gets(newnode->from);
    return newnode;
}

void create_a_list_of_n_node(int n)
{
    int i;
    node *newnode;
    node *temp;
    for (i = 0; i < n; i++)
    {
        newnode = create();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void insert_at_begining()
{

    node *newnode = create();
    if (start)
    {
        start = newnode;
    }
    else
    {
        start->prev = newnode;
        newnode->prev = start;
        newnode->next = start;
        start = newnode;
    }
}
void insert_at_end()
{
    node *newnode = create();
    node *temp;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insert_at_mid()
{
    if (start)
    {
        cout << "Empty Record";
        return;
    }
    else
    {
        node *newnode = create();
        node *temp = start;
        int temp_roll_no;
        cout << "Enter roll no\n";
        cin >> temp_roll_no;

        while (temp->roll_no != temp_roll_no)
        {
            temp = temp->next;
        }
        temp->next->prev = newnode;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}
void delete_at_beg()
{
    node *temp;
    if (start == NULL)
    {
        printf("\n Empty list");
        getchar();
        return;
    }
    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
}
void delete_at_last()
{
    node *temp;
    if (start == NULL)
    {
        printf("\n Empty list");
        getchar();
        return;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)

            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
        temp = NULL;
    }
}
void delete_at_mid()
{
    int i = 0, pos, nodectr;
    node *temp;
    if (start == NULL)
    {
        printf("\n Empty List");
        getchar();
        return;
    }
    else
    {
        printf("\n Enter the position of the node to delete: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if (pos > nodectr)
        {
            printf("\nthis node does not exist");
            getchar();
            return;
        }
        if (pos > 1 && pos < nodectr)
        {
            temp = start;
            i = 1;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
            printf("\n node deleted..");
        }
        else
        {
            printf("\n It is not a middle position..");
            getchar();
        }
    }
}
int countnode(node *start)
{
    if (start == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countnode(start->next);
    }
}
int menu()
{
    int ch;
    printf("\n 1.Create");
    printf("\n------------------------------");
    printf("\n 2. Insert a node at beginning ");
    printf("\n 3. Insert a node at end");
    printf("\n 4. Insert a node at middle");
    printf("\n------------------------------");
    printf("\n 5. Delete a node from beginning");
    printf("\n 6. Delete a node from Last");
    printf("\n 7. Delete a node from Middle");
    printf("\n------------------------------");
    printf("\n 8. Traverse the list from Left to Right");
    printf("\n 9. Traverse the list from Right toLeft ");
    printf("\n------------------------------");
    printf("\n 10.Count the Number of nodes in the list");
    printf("\n 11.Exit ");
    printf("\n\n Enter your choice: ");
    cin >> ch;
    return ch;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ch, n;
    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("\n Enter Number of nodes to create: ");
            scanf("%d", &n);
            create_a_list_of_n_node(n);

            printf("\n List created..");
            break;
        case 2:
            insert_at_begining();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at_mid();
            break;
        case 5:
            delete_at_beg();
            break;
        case 6:
            delete_at_last();
            break;
        case 7:
            delete_at_mid();
            break;
        case 8:
            traverse_left_to_right();
            break;
        case 9:
            traverse_right_to_left();
            break;
        case 10:
            printf("\n Number of nodes: %d", countnode(start));
            break;
        case 11:
            exit(0);
        }
        getchar();
    }
    return 0;
}
