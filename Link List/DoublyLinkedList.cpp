#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void InsertAtHead()
{
    struct node *newNode;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value\n");
    scanf("%d",&item);
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    printf("\nNode inserted");

}

void InsertAtEnd()
{
    struct node *newNode, *tmp;
    int item;
    tmp = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value\n");
    scanf("%d",&item);
    newNode->data = item;
    newNode->next = NULL;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    printf("\nNode inserted At End");
}

void InsertAtSpecificIndex()
{
    struct node *tmp,*newNode,*prv;
    tmp = head;
    int value,idx;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Value and  Index Number which you want to Insert: ");
    scanf("%d %d",&value, &idx);
    newNode->data = value;
    idx--;
    while(idx--)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    newNode->next = tmp;
    prv->next = newNode;
    newNode->prev = prv;
    tmp->prev = newNode;


    printf("\nNode inserted At Specific index");
}

void DeleteFromHead()
{
    struct node *tmp;
    tmp = head;
    head = tmp->next;
    free(tmp);
}


void DeleteAtEnd()
{
    struct node *tmp, *prv;
    tmp = head;
    prv = NULL;
    while(tmp->next != NULL)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    prv->next = NULL;
    free(tmp);
}

void DeleteSpecificIndex()
{
    struct node *tmp,*ptr,*prv;
    tmp = head;
    int idx;
    printf("Enter Index Number which you want to Delete: ");
    scanf("%d",&idx);
    idx--;
    while(idx--)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    ptr = tmp->next;
    prv->next = tmp->next;
    ptr->prev = prv;
    free(tmp);
}


void SearchNodeByValue()
{
    struct node *tmp;
    int item;
    printf("Enter Value which you want to Find: ");
    scanf("%d",&item);
    tmp = head;
    bool flag = false;
    while(tmp->next != NULL)
    {
        if(tmp->data == item)
        {
            flag = true;
            break;
        }
        else tmp = tmp->next;
    }

    if(flag) printf("YES , Found\n");
    else printf("Sorry , Not Found\n");
}


void SearchNodeByPosition()
{
    struct node *tmp;
    tmp = head;
    int idx, m_indx;
    printf("Enter Node position which you want to Find: ");
    scanf("%d",&idx);
    m_indx = idx;
    idx--;
    while(idx--)
    {
        tmp = tmp->next;
    }
    printf("\nYour %d position value is : %d",m_indx,tmp->data);

}


void PrintReverseOrder()
{
    struct node *newNode, *ptr;
    newNode = head;


    printf("\nprinting values . . . . .\n");
    while (newNode!=NULL)
    {
        printf("%d-> ",newNode->data);
        newNode = newNode -> next;
    }
}


void display()
{
    struct node *newNode;
    newNode = head;


    printf("\nprinting values . . . . .\n");
    while (newNode!=NULL)
    {
        printf("%d-> ",newNode->data);
        newNode = newNode -> next;
    }

}


int main ()
{
    int choice =0;
    while(1)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Insertion at the end\n3.Insert at a specific index.\n4.Delete from the head.\n5.Delete from the end\n6.Delete from any specific location.\n7.Search a node by value\n8.Search a node by position\n9.Print in reverse order.\n10.Show\n11.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
            InsertAtHead();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtSpecificIndex();
            break;
        case 4:
            DeleteFromHead();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteSpecificIndex();
            break;
        case 7:
            SearchNodeByValue();
            break;
        case 8:
            SearchNodeByPosition();
            break;
        case 9:
           // PrintReverseOrder();
            break;
        case 10:
            display();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }

    return 0;
}


